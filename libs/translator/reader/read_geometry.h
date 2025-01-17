//
// SPDX-License-Identifier: Apache-2.0
//

// Copyright 2022 Autodesk, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
#pragma once

#include <ai_nodes.h>

#include <pxr/usd/usd/prim.h>

#include <string>
#include <unordered_map>
#include <vector>

#include "prim_reader.h"

PXR_NAMESPACE_USING_DIRECTIVE

// Register readers for the USD builtin Geometries

REGISTER_PRIM_READER(UsdArnoldReadMesh, AI_NODE_SHAPE);
REGISTER_PRIM_READER(UsdArnoldReadCurves, AI_NODE_SHAPE);
REGISTER_PRIM_READER(UsdArnoldReadPoints, AI_NODE_SHAPE);
REGISTER_PRIM_READER(UsdArnoldReadCube, AI_NODE_SHAPE);
REGISTER_PRIM_READER(UsdArnoldReadSphere, AI_NODE_SHAPE);
REGISTER_PRIM_READER(UsdArnoldReadCylinder, AI_NODE_SHAPE);
REGISTER_PRIM_READER(UsdArnoldReadCone, AI_NODE_SHAPE);
REGISTER_PRIM_READER(UsdArnoldReadCapsule, AI_NODE_SHAPE);
REGISTER_PRIM_READER(UsdArnoldReadPointInstancer, AI_NODE_SHAPE);
REGISTER_PRIM_READER(UsdArnoldReadVolume, AI_NODE_SHAPE);
REGISTER_PRIM_READER(UsdArnoldReadProceduralCustom, AI_NODE_SHAPE);


class UsdArnoldReadBounds : public UsdArnoldPrimReader {
public:
    UsdArnoldReadBounds(const AtParamValueMap *params = nullptr)
        : UsdArnoldPrimReader(AI_NODE_SHAPE), _params(params)
    {
    }
    void Read(const UsdPrim &prim, UsdArnoldReaderContext &context) override;

private:
    const AtParamValueMap *_params;
};

class UsdArnoldReadGenericPoints : public UsdArnoldPrimReader {
public:
    UsdArnoldReadGenericPoints(const AtParamValueMap *params = nullptr)
        : UsdArnoldPrimReader(AI_NODE_SHAPE), _params(params)
    {
    }
    void Read(const UsdPrim &prim, UsdArnoldReaderContext &context) override;

private:
    const AtParamValueMap *_params;
};

class UsdArnoldReadGenericPolygons : public UsdArnoldPrimReader {
public:
    UsdArnoldReadGenericPolygons(const AtParamValueMap *params = nullptr)
        : UsdArnoldPrimReader(AI_NODE_SHAPE), _params(params)
    {
    }
    void Read(const UsdPrim &prim, UsdArnoldReaderContext &context) override;

private:
    const AtParamValueMap *_params;
};


class UsdArnoldReadProcViewport : public UsdArnoldPrimReader {
public:
    UsdArnoldReadProcViewport(const std::string &procName, AtProcViewportMode mode, const AtParamValueMap *params = nullptr)
        : UsdArnoldPrimReader(AI_NODE_SHAPE), _procName(procName), _mode(mode), _params(params)
    {
    }
    void Read(const UsdPrim &prim, UsdArnoldReaderContext &context) override;

private:
    std::string _procName;
    AtProcViewportMode _mode;
    const AtParamValueMap *_params;
};
