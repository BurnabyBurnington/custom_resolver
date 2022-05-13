#!/usr/bin/env python
# -*- coding: utf-8 -*-

"""This module tests if the custom resolver works."""

# IMPORT FUTURE LIBRARIES
from __future__ import print_function

# IMPORT THIRD-PARTY LIBRARIES
from pxr import Ar


def main():
    """Run the main execution of the current script."""
    print("This should work", Ar.GetResolver().Resolve("Table.usda"))

    # resolverContext = _ConfigureAssetResolver(args, resolver)
    # with Ar.ResolverContextBinder(resolverContext):
    #     inputPath = _AnchorRelativePath(args, resolver)
    #     resolved = resolver.Resolve(inputPath)


if __name__ == "__main__":
    main()
