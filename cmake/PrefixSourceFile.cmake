RENMS_FILE_PREFIX_STR = "\
/**\n\
 * @file @SOURCE_NAME@\n\
 * @author VITALISED & Contributors\n\
 * @date @SOURCE_DATE@\n\
 * \n\
 * \n\
 * \n\
 * Copyright (C) 2023  VITALISED & Contributors\n\
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


# this function: iterates all files, gets their name component, checks if they've already been prepended with relevant infos
# then prepends the docstring and configures any relevant values
function(AddSourcePrefixes SOURCES)
    foreach(SOURCE_FILE ${SOURCES})
        file(READ ${SOURCE_FILE} TEXT)

        string(FIND ${TEXT} "* @file" TEXT_SUBSTR_POS)

        if(${TEXT_SUBSTR_POS} == -1)
            get_filename_component(SOURCE_NAME ${SOURCE_FILE} NAME)

            string(PREPEND TEXT ${RENMS_FILE_PREFIX_STR})

            file(WRITE ${SOURCE_FILE} ${TEXT})

            string(TIMESTAMP SOURCE_DATE "%Y-%m-%d")

            configure_file(${SOURCE_FILE} ${SOURCE_FILE} @ONLY)
        endif()
    endforeach()
endfunction()
