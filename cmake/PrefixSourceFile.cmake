# this function checks if the current source file has @file, if not prepends the
# current source file prelude specified below and replaces all values surrounded
# in @
macro(add_sources_prefix_renms SOURCE_FILE_RENMS)
    message(${SOURCE_FILE_RENMS})

    file(READ ${SOURCE_FILE_RENMS} TEXT)

    if(NOT TEXT MATCHES "@file")
        get_filename_component(SOURCE_NAME_RENMS ${SOURCE_FILE_RENMS} NAME)

        string(
            CONCAT
                OUTPUT_SOURCE_RENMS
                "\
/**\n\
 * @file @SOURCE_NAME_RENMS@\n\
 * @author VITALISED & Contributors\n\
 * @since @SOURCE_DATE@\n\
 * \n\
 * Copyright (C) @SOURCE_YEAR@  VITALISED & Contributors\n\
 * \n\
 * This program is free software: you can redistribute it and/or modify\n\
 * it under the terms of the GNU General Public License as published by\n\
 * the Free Software Foundation, either version 3 of the License, or\n\
 * (at your option) any later version.\n\
 * \n\
 * This program is distributed in the hope that it will be useful,\n\
 * but WITHOUT ANY WARRANTY; without even the implied warranty of\n\
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n\
 * GNU General Public License for more details.\n\
 * \n\
 * You should have received a copy of the GNU General Public License\n\
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.\n\
 */\n\n"
                "${TEXT}"
        )

        string(REPLACE @SOURCE_NAME_RENMS@ ${SOURCE_NAME_RENMS}
                       OUTPUT_SOURCE_RENMS "${OUTPUT_SOURCE_RENMS}"
        )

        string(TIMESTAMP SOURCE_DATE "%Y-%m-%d")
        string(REPLACE @SOURCE_DATE@ ${SOURCE_DATE} OUTPUT_SOURCE_RENMS
                       "${OUTPUT_SOURCE_RENMS}"
        )

        string(TIMESTAMP SOURCE_YEAR "%Y")
        string(REPLACE @SOURCE_YEAR@ ${SOURCE_YEAR} OUTPUT_SOURCE_RENMS
                       "${OUTPUT_SOURCE_RENMS}"
        )

        message(${OUTPUT_SOURCE_RENMS})
        file(WRITE ${SOURCE_FILE_RENMS} "${OUTPUT_SOURCE_RENMS}")
    endif()
endmacro()
