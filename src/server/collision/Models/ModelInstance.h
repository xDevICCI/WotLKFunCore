/* WotLKFunCore is a custom fun server built for
* World of Warcarft game build 3.3.5b. (12345)
*
* Copyright (C) 2008-2016 JustACore.
* Copyright (C) 2008-2016 TrinityCore.
* Copyright (C) 2005-2016 MaNGOS.
*
* ==== Start of GNU GPL ====
*
* This file is free software; as a special exception the author gives
* unlimited permission to copy and/or distribute it, with or without
* modifications, as long as this notice is preserved.
*
* This program is distributed in the hope that it will be useful, but
* WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
* implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*
* ==== End of GNU GPL ====
*/

#ifndef _MODELINSTANCE_H_
#define _MODELINSTANCE_H_

#include <G3D/Matrix3.h>
#include <G3D/Vector3.h>
#include <G3D/AABox.h>
#include <G3D/Ray.h>

#include "Define.h"

namespace VMAP
{
    class WorldModel;
    struct AreaInfo;
    struct LocationInfo;

    enum ModelFlags
    {
        MOD_M2 = 1,
        MOD_WORLDSPAWN = 1<<1,
        MOD_HAS_BOUND = 1<<2
    };

    class ModelSpawn
    {
        public:
            //mapID, tileX, tileY, Flags, ID, Pos, Rot, Scale, Bound_lo, Bound_hi, name
            uint32 flags;
            uint16 adtId;
            uint32 ID;
            G3D::Vector3 iPos;
            G3D::Vector3 iRot;
            float iScale;
            G3D::AABox iBound;
            std::string name;
            bool operator==(const ModelSpawn &other) const { return ID == other.ID; }
            //uint32 hashCode() const { return ID; }
            // temp?
            const G3D::AABox& getBounds() const { return iBound; }

            static bool readFromFile(FILE* rf, ModelSpawn &spawn);
            static bool writeToFile(FILE* rw, const ModelSpawn &spawn);
    };

    class ModelInstance: public ModelSpawn
    {
        public:
            ModelInstance(): iModel(0) {}
            ModelInstance(const ModelSpawn &spawn, WorldModel* model);
            void setUnloaded() { iModel = 0; }
            bool intersectRay(const G3D::Ray& pRay, float& pMaxDist, bool pStopAtFirstHit) const;
            void intersectPoint(const G3D::Vector3& p, AreaInfo &info) const;
            bool GetLocationInfo(const G3D::Vector3& p, LocationInfo &info) const;
            bool GetLiquidLevel(const G3D::Vector3& p, LocationInfo &info, float &liqHeight) const;
        protected:
            G3D::Matrix3 iInvRot;
            float iInvScale;
            WorldModel* iModel;
    };
} // namespace VMAP

#endif // _MODELINSTANCE
