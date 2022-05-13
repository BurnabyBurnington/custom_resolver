#include <iostream>

// IMPORT THIRD-PARTY LIBRARIES
#include <pxr/usd/ar/defaultResolver.h>
#include <pxr/usd/ar/defineResolver.h>

// IMPORT LOCAL LIBRARIES
#include "resolver.h"

PXR_NAMESPACE_OPEN_SCOPE

AR_DEFINE_RESOLVER(URIResolver, ArResolver)

namespace
{
    const std::string SPECIAL_IDENTIFIER = "Table";
}

URIResolver::URIResolver() : ArDefaultResolver() {}

URIResolver::~URIResolver() = default;


bool URIResolver::IsRelativePath(const std::string& path) {
    if (path != SPECIAL_IDENTIFIER)
    {
        return pxr::ArDefaultResolver::IsRelativePath(path);
    }

    // Don't try to absolutize our SPECIAL_IDENTIFIER
    return false;
}


std::string URIResolver::Resolve(const std::string& path) {
    std::cout << "URIResolver::Resolve: " << path << '\n';

    if (path == SPECIAL_IDENTIFIER)
    {
        return "./Table/Table.usda";
    }

    return pxr::ArDefaultResolver::Resolve(path);
}

std::string URIResolver::ResolveWithAssetInfo(
    const std::string& path, pxr::ArAssetInfo* assetInfo
)
{
    std::cout << "URIResolver::ResolveWithAssetInfo: " << path << '\n';

    if (path != SPECIAL_IDENTIFIER)
    {
        std::cout << "Path is not special " << path << '\n';
        std::cout << "Got " << pxr::ArDefaultResolver::ResolveWithAssetInfo(path, assetInfo) << '\n';

        return pxr::ArDefaultResolver::ResolveWithAssetInfo(path, assetInfo);
    }

    return "/home/selecaoone/repositories/custom_resolver/regular_resolve_test/Table/Table.usda";
    return "./Table/Table.usda";
}


PXR_NAMESPACE_CLOSE_SCOPE
