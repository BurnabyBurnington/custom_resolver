#pragma once

// IMPORT THIRD-PARTY LIBRARIES
#include <pxr/usd/ar/defaultResolver.h>

PXR_NAMESPACE_OPEN_SCOPE

class URIResolver : public ArDefaultResolver {
public:
    URIResolver();
    ~URIResolver();

    bool IsRelativePath(const std::string& path) override;

    std::string Resolve(const std::string& path) override;

    virtual std::string ResolveWithAssetInfo(
        const std::string& path,
        ArAssetInfo* assetInfo
    ) override;
};

PXR_NAMESPACE_CLOSE_SCOPE
