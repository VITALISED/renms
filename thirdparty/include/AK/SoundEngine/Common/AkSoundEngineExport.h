/*******************************************************************************
The content of this file includes portions of the AUDIOKINETIC Wwise Technology
released in source code form as part of the SDK installer package.

Commercial License Usage

Licensees holding valid commercial licenses to the AUDIOKINETIC Wwise Technology
may use this file in accordance with the end user license agreement provided 
with the software or, alternatively, in accordance with the terms contained in a
written agreement between you and Audiokinetic Inc.

Apache License Usage

Alternatively, this file may be used under the Apache License, Version 2.0 (the 
"Apache License"); you may not use this file except in compliance with the 
Apache License. You may obtain a copy of the Apache License at 
http://www.apache.org/licenses/LICENSE-2.0.

Unless required by applicable law or agreed to in writing, software distributed
under the Apache License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES
OR CONDITIONS OF ANY KIND, either express or implied. See the Apache License for
the specific language governing permissions and limitations under the License.

  Copyright (c) 2023 Audiokinetic Inc.
*******************************************************************************/

// AkSoundEngineExport.h

/// \file 
/// Export/calling convention definitions.

#ifndef _AK_SOUNDENGINE_EXPORT_H_
#define _AK_SOUNDENGINE_EXPORT_H_

#include <AK/AkPlatforms.h>

#ifndef AK_DLLEXPORT
#define AK_DLLEXPORT
#endif

#ifndef AK_DLLIMPORT
#define AK_DLLIMPORT
#endif

#ifndef AK_ATTR_USED
#define AK_ATTR_USED
#endif

#ifdef AKSOUNDENGINE_DLL
	#ifdef AKSOUNDENGINE_EXPORTS
	/// Sound Engine API import/export definition
	#define AKSOUNDENGINE_API AK_DLLEXPORT
	#else
	/// Sound Engine API import/export definition		
	#define AKSOUNDENGINE_API AK_DLLIMPORT
	#endif // Export
#else
	#define AKSOUNDENGINE_API	
#endif

#ifndef AKSOUNDENGINE_CALL
	#define AKSOUNDENGINE_CALL	
#endif

/// Declare a function
/// \param _type Return type of the function
/// \param _name Name of the function
/// \remarks This must be followed by the parentheses containing the function arguments declaration
#define AK_FUNC( _type, _name ) _type AKSOUNDENGINE_CALL _name

/// Declare an extern function
/// \param _type Return type of the function
/// \param _name Name of the function
/// \remarks This must be followed by the parentheses containing the function arguments declaration
#define AK_EXTERNFUNC( _type, _name ) extern _type AKSOUNDENGINE_CALL _name

/// Declare an extern function that is exported/imported
/// \param _type Return type of the function
/// \param _name Name of the function
/// \remarks This must be followed by the parentheses containing the function arguments declaration
#define AK_EXTERNAPIFUNC( _type, _name ) extern AKSOUNDENGINE_API _type AKSOUNDENGINE_CALL _name

/// Declare a callback function type
/// \param _type Return type of the function
/// \param _name Name of the function
/// \remarks This must be followed by the parentheses containing the function arguments declaration
#define AK_CALLBACK( _type, _name ) typedef _type ( AKSOUNDENGINE_CALL *_name )

#endif  //_AK_SOUNDENGINE_EXPORT_H_
