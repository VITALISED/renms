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

#pragma once

#include <stdint.h>
#include <string>

namespace AK
{
	namespace WwiseAuthoringAPI
	{
#define AkGuidIsEqual(rguid1, rguid2) ( \
        ((uint32_t*) rguid1)[0] == ((uint32_t*) rguid2)[0] && \
        ((uint32_t*) rguid1)[1] == ((uint32_t*) rguid2)[1] && \
        ((uint32_t*) rguid1)[2] == ((uint32_t*) rguid2)[2] && \
        ((uint32_t*) rguid1)[3] == ((uint32_t*) rguid2)[3] )

		struct AkGuid
		{
			AkGuid() = default;

			AkGuid( const AkGuid& other )
			{
				memcpy( this, &other, sizeof other );
			}

		#ifdef GUID_DEFINED
			AkGuid( const GUID& guid )
			{
				*this = guid;
			}
			inline AkGuid& operator=(const GUID& other)
			{
				return *this = * reinterpret_cast<const AkGuid*>( &other );
			}
			inline operator GUID() const
			{
				return *reinterpret_cast<const GUID*>(this);
			}

			inline bool operator==(const GUID& other) const
			{
				return AkGuidIsEqual(this, &other);
			}

			inline bool operator!=(const GUID& other) const
			{
				return !AkGuidIsEqual(this, &other);
			}
		#endif

			inline bool operator==(const AkGuid& other) const
			{
				return AkGuidIsEqual(this, &other);
			}

			inline bool operator!=(const AkGuid& other) const
			{
				return !AkGuidIsEqual(this, &other);
			}

			inline AkGuid& operator=(const AkGuid& other)
			{
				memcpy( this, &other, sizeof other );
				return *this;
			}

			inline bool IsNull() const
			{
				for (int i = 0; i < 8; ++i)
				{
					if (data4[i] != 0)
					{
						return false;
					}
				}

				return (data1 == 0 && data2 == 0 && data3 == 0);
			}

			inline AkGuid& Nullify()
			{
				memset(this, 0, sizeof(AkGuid));
				return *this;
			}

			uint32_t data1;
			uint16_t data2;
			uint16_t data3;
			uint8_t data4[8];
		};
	}
}
