/*
    Copyright (C) 2023  VITALISED, tractorbeam

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#pragma once

#include <skyscraper.h>
#include <stdio.h>
#include <cstring>
#include "rapidxml.h"

#if defined( _MSC_VER ) && _MSC_VER >= 1400
#	pragma warning( push )
#	pragma warning( disable : 4996 )  // Disable deprecation warnings
#endif

#ifdef RAPIDXML_NO_EXCEPTIONS
inline void rapidxml::parse_error_handler( const char *what, void *where )
{
	// When not using exceptions, program has to be terminated on xml error
	fprintf( stderr, "Parse error: %s\n", what );
	std::abort();
}
#endif

SKYSCRAPER_BEGIN

class XMLAttribute
{
public:
	XMLAttribute() : attrib( 0x0 ) {}
	XMLAttribute( rapidxml::xml_attribute<> *attrib ) : attrib( attrib ) {}

	bool isEmpty() const { return attrib == 0x0; }
	const char *getName() const { return attrib->name(); }
	const char *getValue() const { return attrib->value(); }

	XMLAttribute getNextAttrib() const { return XMLAttribute( attrib->next_attribute( 0x0 ) ); }

protected:
	rapidxml::xml_attribute<>  *attrib;
};


class XMLNode
{
public:
	XMLNode() : node( 0x0 ) {}
	XMLNode( rapidxml::xml_node<> *node ) : node( node ) {}

	rapidxml::xml_node<> *getRapidXMLNode() const { return node; }
	
	bool isEmpty() const { return node == 0x0; }
	const char *getName() const { return node->name(); }
	const char *getText() const { return node->value(); }
	XMLNode getFirstChild( const char *name = 0x0 ) const { return XMLNode( node->first_node( name ) ); }
	XMLNode getNextSibling( const char *name = 0x0 ) const { return XMLNode( node->next_sibling( name ) ); }

	XMLAttribute getFirstAttrib() const { return XMLAttribute( node->first_attribute( 0x0 ) ); }
	const char *getAttribute ( const char *name, const char *defValue = "" ) const
	{
		rapidxml::xml_attribute<> *attrib = node->first_attribute( name );
		return attrib != 0x0 ? (const char *)attrib->value() : defValue;
	}

	int countChildNodes( const char *name = 0x0 ) const
	{
		int numNodes = 0;
		rapidxml::xml_node<> *node1 = node->first_node( name );
		while( node1 )
		{
			++numNodes;
			node1 = node1->next_sibling( name );
		}
		return numNodes;
	}

protected:
	rapidxml::xml_node<>  *node;
};


class XMLDoc
{
public:
	XMLDoc() : buf( 0x0 ), err(false) {}
	~XMLDoc() { delete[] buf; }
	
	bool hasError() const { return err || doc.first_node() == 0x0; }
	XMLNode getRootNode() const { return XMLNode( doc.first_node() ); }
	
	void parseString( char *text )
	{
#ifdef RAPIDXML_NO_EXCEPTIONS
		doc.parse< rapidxml::parse_validate_closing_tags >( text );
#else
		try { doc.parse< rapidxml::parse_validate_closing_tags >( text ); }
		catch (const std::exception&) { err = true; }
#endif
	}

	void parseBuffer( const char *charbuf, int size )
	{
		buf = new char[size + 1];
		memcpy( buf, charbuf, size );
		buf[size] = '\0';

		parseString( buf );
	}

	bool parseFile( const char *fileName )
	{
		FILE *f = fopen( fileName, "rb" );
		if( f == 0x0 ) return false;

		fseek( f, 0, SEEK_END );
		int size = ftell( f );
		fseek( f, 0, SEEK_SET );
		
		buf = new char[size + 1];
		fread( buf, 1, size, f );
		buf[size] = '\0';

		fclose( f );

		parseString( buf );
		return true;
	}

private:
	rapidxml::xml_document<>  doc;
	char                      *buf;
	bool                      err;
};

#if defined( _MSC_VER ) && _MSC_VER >= 1400
#	pragma warning( pop )
#endif

SKYSCRAPER_END