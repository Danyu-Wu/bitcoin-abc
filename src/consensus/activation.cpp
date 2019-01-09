// Copyright (c) 2018 The Bitcoin developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "activation.h"

#include "chain.h"
#include "chainparams.h"
#include "config.h"
#include "util.h"

static bool IsUAHFenabled(const Config &config, int nHeight) {
    return nHeight >= config.GetChainParams().GetConsensus().uahfHeight;
}

bool IsUAHFenabled(const Config &config, const CBlockIndex *pindexPrev) {
    if (pindexPrev == nullptr) {
        return false;
    }

    return IsUAHFenabled(config, pindexPrev->nHeight);
}

static bool IsDAAEnabled(const Config &config, int nHeight) {
    return nHeight >= config.GetChainParams().GetConsensus().daaHeight;
}

bool IsDAAEnabled(const Config &config, const CBlockIndex *pindexPrev) {
    if (pindexPrev == nullptr) {
        return false;
    }

    return IsDAAEnabled(config, pindexPrev->nHeight);
}

bool IsMagneticAnomalyEnabled(const Config &config, int64_t nMedianTimePast) {
    return nMedianTimePast >= gArgs.GetArg("-magneticanomalyactivationtime",
                                           config.GetChainParams()
                                               .GetConsensus()
                                               .magneticAnomalyActivationTime);
}

bool IsMagneticAnomalyEnabled(const Config &config,
                              const CBlockIndex *pindexPrev) {
    if (pindexPrev == nullptr) {
        return false;
    }

    return IsMagneticAnomalyEnabled(config, pindexPrev->GetMedianTimePast());
}

bool IsGreatWallEnabled(const Config &config, int64_t nMedianTimePast) {
    return nMedianTimePast >= gArgs.GetArg("-greatwallactivationtime",
                                           config.GetChainParams()
                                               .GetConsensus()
                                               .greatWallActivationTime);
}

bool IsGreatWallEnabled(const Config &config,
                              const CBlockIndex *pindexPrev) {
    if (pindexPrev == nullptr) {
        return false;
    }

	return IsGreatWallEnabled(config, pindexPrev->GetMedianTimePast());
}

bool IsShortSpacingEnabled(const Config &config,
                              const int height,
							  int *shortSpacingHeight) {

	int heightExt = gArgs.GetArg("-shortspacingactivationheight", 0);
	int heightInt = config.GetChainParams().GetConsensus().shortSpacingHeight;
	if (heightExt) {
		if (shortSpacingHeight != nullptr)
			*shortSpacingHeight = heightExt;
		return height >= heightExt;
	}
	else if (heightInt) {
		if (shortSpacingHeight != nullptr)
			*shortSpacingHeight = heightInt;
		return height >= heightInt;
	}
	else {
		if (shortSpacingHeight != nullptr)
			*shortSpacingHeight = 0;
		return false;
	}
}