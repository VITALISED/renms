# Atlas Metadata PSA

The classes in recv/requests seem to have been at one point actual metadata registrars, they have class name hashes (though we aren't quite sure what they are) and generally follow the structure of other metadata types.

## Some theories

- They might have stripped the metadata for security reasons
- These classes are virtual, they might not be supported in the metadata compiler they use and were ported over and maintained manually
