# Globals

Globals are also metadata, however aren't registered and are just seemingly statically linked in the binary, so Heridium can't really work with them right now. However they can still be dumped by scanning the image since they're still stored as a cTkMetaDataClass object somewhere, so keep that in mind if you're working from a newer build.
