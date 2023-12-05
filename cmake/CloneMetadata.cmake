function(GetMetadataForVersion TAGNAME)
    execute_process(
        COMMAND git clone -b ${TAGNAME} https://github.com/VITALISED/renms
    )
endfunction()
