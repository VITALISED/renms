#include <engine/source/engine/EgScene.h>

#include <skyscraper.h>

SKYSCRAPER_BEGIN

// class Tokenizer
// {
// public:
	
// 	Tokenizer( const char *data ) : _p( data ), _line( 1 ) { getNextToken(); }

// 	int getLine() const { return _line; }

// 	bool hasToken() const { return _token[0] != '\0'; }
	
// 	bool checkToken( const char *token, bool peekOnly = false )
// 	{
// 		if( _stricmp( _token, token ) == 0 )
// 		{
// 			if( !peekOnly ) getNextToken();
// 			return true;
// 		}
// 		return false;
// 	}

// 	const char *getToken( const char *charset )
// 	{
// 		if( charset )
// 		{
// 			// Validate token
// 			const char *p = _token;
// 			while( *p )
// 			{
// 				if( strchr( charset, *p++ ) == 0x0 )
// 				{
// 					_prevToken[0] = '\0';
// 					return _prevToken;
// 				}
// 			}
// 		}
		
// 		memcpy( _prevToken, _token, tokenSize );
// 		getNextToken();
// 		return _prevToken;
// 	}

// 	bool seekToken( const char *token )
// 	{
// 		while( _stricmp( getToken( 0x0 ), token ) != 0 )
// 		{
// 			if( !hasToken() ) return false;
// 		}
// 		return true;
// 	}

// protected:	
	
// 	void checkLineChange()
// 	{
// 		if( *_p == '\r' && *(_p+1) == '\n' )
// 		{
// 			++_p;
// 			++_line;
// 		}
// 		else if( *_p == '\r' || *_p == '\n' ) ++_line;
// 	}

// 	void skip( const char *chars )
// 	{
// 		while( *_p )
// 		{
// 			if( !strchr( chars, *_p ) ) break;
// 			checkLineChange();
// 			++_p;
// 		}
// 	}
	
// 	bool seekChar( const char *chars )
// 	{
// 		while( *_p )
// 		{
// 			if( strchr( chars, *_p ) ) break;
// 			checkLineChange();
// 			++_p;
// 		}
// 		return *_p != '\0';
// 	}
	
// 	void getNextToken()
// 	{
// 		// Skip whitespace
// 		skip( " \t\n\r" );

// 		// Parse token
// 		const char *p0 = _p, *p1 = _p;
// 		if( *_p == '"' )  // Handle string
// 		{
// 			++_p; ++p0;
// 			if( seekChar( "\"\n\r" ) ) p1 = _p++;
// 		}
// 		else
// 		{
// 			seekChar( " \t\n\r{}()<>=,;" );  // Advance until whitespace or special char found
// 			if( _p == p0 && *_p != '\0' ) ++_p;  // Handle special char
// 			p1 = _p;
// 		}
// 		memcpy( _token, p0, std::min( (ptrdiff_t)(p1 - p0), tokenSize-1 ) );
// 		_token[std::min( (ptrdiff_t)(p1 - p0), tokenSize-1 )] = '\0';
// 	}

// protected:

// 	static const ptrdiff_t tokenSize = 128;
	
// 	char        _token[tokenSize], _prevToken[tokenSize];
// 	const char  *_p;
// 	int         _line;
// };

// bool ShaderResource::parseFXSection( char *data )
// {
// 	// Preprocessing: Replace comments with whitespace
// 	char *p = data;
// 	while( *p )
// 	{
// 		if( *p == '/' && *(p+1) == '/' )
// 		{
// 			while( *p && *p != '\n' && *p != '\r' )
// 				*p++ = ' ';
// 			if( *p == '\0' ) break;
// 		}
// 		else if( *p == '/' && *(p+1) == '*' )
// 		{
// 			*p++ = ' '; *p++ = ' ';
// 			while( *p && (*p != '*' || *(p+1) != '/') )
// 				*p++ = ' ';
// 			if( *p == '\0' ) return std::printf( "FX: Expected */" );
// 			*p++ = ' '; *p++ = ' ';
// 		}
// 		++p;
// 	}
// }

SKYSCRAPER_END