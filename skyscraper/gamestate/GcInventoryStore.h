/**
 * @file GcInventoryStore.h
 * @author VITALISED & Contributors
 * @since 2023-12-09
 *
 * Copyright (C) 2023  VITALISED & Contributors
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#pragma once

#include <skyscraper.h>

#include <toolkit/core/types/TkID.h>
#include <toolkit/utilities/containers/TkBitArray.h>
#include <toolkit/utilities/containers/TkUnorderedMap.h>
#include <toolkit/utilities/containers/TkVector.h>

#include <gamestate/gcinventorycontainer.meta.h>
#include <gamestate/gcinventoryelement.meta.h>
#include <gamestate/gcinventorylayout.meta.h>
#include <gamestate/gcinventoryspecialslot.meta.h>
#include <reality/gcinventorybasestatentry.meta.h>
#include <reality/gcinventoryclass.meta.h>
#include <reality/gcinventorygenerationbasestatdata.meta.h>
#include <reality/gcinventorylayoutgenerationdataentry.meta.h>
#include <reality/gcinventorylayoutsizetype.meta.h>
#include <reality/gcinventorystacksizegroup.meta.h>
#include <reality/gcproductdata.meta.h>
#include <reality/gcrealitysubstancedata.meta.h>
#include <reality/gctechnology.meta.h>
#include <simulation/components/utils/gcinventorytechprobability.meta.h>
#include <simulation/gcspaceshipclasses.meta.h>
#include <simulation/gcweaponclasses.meta.h>
#include <toolkit/tkmodelrendererdata.meta.h>

SKYSCRAPER_BEGIN

enum LayoutGenerationMode : uint8_t
{
    Normal,
    LimitSizeUsingCurrent,
};

enum LayoutCompareGenerationType
{
    MoreThanCurrent,
    MuchMoreThanCurrent,
    SameAsCurrent,
    CompareSizeType,
};

enum InventoryChoice
{
    _None = -1,
    Personal,
    Personal_TechOnly,
    Personal_Cargo,
    Weapon,
    Ship,
    Ship_TechOnly,
    Ship_Cargo,
    Freighter,
    Freighter_TechOnly,
    Freighter_Cargo,
    _Vehicle,
    Vehicle_TechOnly,
    Chest1,
    Chest2,
    Chest3,
    Chest4,
    Chest5,
    Chest6,
    Chest7,
    Chest8,
    Chest9,
    Chest10,
    ChestMagic,
    ChestMagic2,
    MaintenanceObject,
    FrontendPage,
    CookingIngredients,
    RocketLocker,
    Num_Choices,
};

class InventoryData
{
  public:
    uint8_t mePlayerInventory[4];
    cTkSmartResHandle mModelResHandle;
    cTkModelRendererData *mpModelRenderData;
    TkID<256> mInventoryName;
};

class InventoryTransferData
{
  public:
    cTkVector<InventoryData> maLeft;
    int miCurrentLeft;
    cTkVector<InventoryData> maRight;
    int miCurrentRight;
};

class cGcInventoryStore
{
  public:
    cGcInventoryIndex &Add(const cGcInventoryElement &lItem);
    void AddSlotsWithCapacity(InventoryChoice leType, int liIncrease, bool, eShipClass leShipClass);
    void BreakAndBlockSlotsWithTech(const cTkSeed &lSeed, float lfBreakProbability, bool lbIsShip, int liSkipSlots);
    void BreakCrashedShipSlots(const cTkSeed &lSeed, float lfBreakProbability, int liSkipSlots);
    void BreakShipItems(const cTkSeed &lSeed, float lfBreakProbability);
    bool CanInventoryStoreTechnology(
        InventoryChoice leInventoryChoice, const cGcTechnology &lTechnology, eShipClass leShipClass);
    void CheckAndEnableTechBonusSlots(InventoryChoice leChoice, cTkSeed lSeed);
    void CheckAndEnableTechBonusSlotsFromDefaultContainer(const cGcInventoryContainer &lInventoryContainer);
    void CheckAndUpateBaseStats(
        InventoryChoice leType, const cTkSeed &lSeed, eInventoryClass leInventoryClass, eShipClass leShipClass);
    void ClearEmptyItems();
    void ClearItems();
    void CopyInventoryStore(const cGcInventoryStore &lInventory);
    const cGcInventoryElement &CreateProductElement(const cGcProductData &lProduct, int liAmount, int liMaxAmount);
    const cGcInventoryElement &CreateSubstanceElement(
        const cGcRealitySubstanceData &lSubstance, int liAmount, int liMaxAmount);
    const cGcInventoryElement &CreateTechElement(const cGcTechnology &lTech, int liAmount);
    const cGcInventoryElement &CreateTechnologyElement(const cGcTechnology &lTechnology, int liAmount, int liMaxAmount);
    bool DamageRandomTech(const cTkSeed &lSeed);
    bool DoesSlotGiveTechBonus(const cGcInventoryIndex &lIndex);
    void EnforceStackSizeLimitsOnAllItems();
    void GenerateFreighterSubstances(const cTkSeed &lSeed);
    void GenerateLayoutByInventoryType(const cTkSeed &lSeed, InventoryChoice leType);
    void GenerateLayoutSimple(int liWidth, int liHeight, eInventoryStackSizeGroup leStackSizeGroup);
    void GeneratePersonalLayout(int liSlots);
    void GenerateProceduralBaseStats(
        InventoryChoice leType, const cTkSeed &lSeed, eInventoryClass leInventoryClass, eShipClass leShipClass,
        eWeaponStatClass leWeaponClass, bool lbForceWorst, bool);
    void GenerateProceduralClass(const cTkSeed &lSeed);
    void GenerateProceduralInventory(
        InventoryChoice leType, TkHandle lNode, const cTkSeed &lSeed, int, LayoutGenerationMode leMode,
        LayoutCompareGenerationType leCompareType, eInventoryClass leClassOverride);
    void GenerateProceduralInventory(
        InventoryChoice leType, TkStrongType<int, TkStrongTypeIDs::TkResHandleID> lResource, const cTkSeed &lSeed, int,
        LayoutGenerationMode leMode, LayoutCompareGenerationType leCompareType, eInventoryClass leClassOverride);
    void GenerateProceduralInventory(
        InventoryChoice leType, const cTkSeed &lSeed, int, LayoutGenerationMode leMode,
        LayoutCompareGenerationType leCompareType, eInventoryClass leClassOverride);
    void GenerateProceduralLayout(InventoryChoice leType, const cTkSeed &lSeed, eSizeType leSizeType);
    void GenerateProceduralLayoutVersion0(
        InventoryChoice leType, int liSlotNumber, const cTkSeed &lSeed, int liLevel, eSizeType leSizeType,
        LayoutGenerationMode leMode, LayoutCompareGenerationType leCompareType, bool lbForceCapacityFromSlotNumber);
    void GenerateProceduralTechnology(
        InventoryChoice leType, const cTkSeed &lSeed, eShipClass leShipClass,
        cTkVector<cGcInventoryTechProbability> &lDesiredTechs);
    const cGcInventoryGenerationBaseStatData *GetBaseStatsData(
        InventoryChoice leType, eShipClass leShipClass, eWeaponStatClass leWeaponClass);
    eInventoryClass GetClass();
    float GetCost(InventoryChoice leType, eShipClass leShipClass, eWeaponStatClass leWeaponClass, bool lbIgnoreIsFree);
    float GetCostRepairSlot(
        int liNumBrokenSlots, InventoryChoice leType, eShipClass leShipClass, eWeaponStatClass leWeaponClass);
    float GetCostTradeIn(
        InventoryChoice leType, eShipClass leShipClass, eWeaponStatClass leWeaponClass, bool lbIgnoreIsFree);
    const cGcInventoryElement *GetElement(const cGcInventoryIndex &lIndex);
    cGcInventoryElement *GetElementForEditing(const cGcInventoryIndex &lIndex);
    cGcInventoryIndex &GetFirstFreeSlot();
    int16_t GetMaxCapacity(InventoryChoice leType, eShipClass leShipClass);
    void GetMinMaxInventoryIndex(
        cGcInventoryIndex &lOutMinIndex, cGcInventoryIndex &lOutMaxIndex, bool lbOnlyCountValidSlots);
    const cGcInventoryIndex &GetNextInvalidSlot();
    float GetNodeSlotsAndTechs(
        TkHandle lNode, cTkVector<cGcInventoryTechProbability> &lDesiredTechs, eSizeType &leSizeType, bool &lbIsCool,
        const cTkSeed &lSeed);
    int GetNumSlots();
    int GetNumSlotsFree();
    int GetNumSpecialSlots(eInventorySpecialSlotType leType);
    int GetProductSlotMaxStorage(const TkID<128> &lProduct);
    float GetResourceSlotsAndTechs(
        TkStrongType<int, TkStrongTypeIDs::TkResHandleID> lResource,
        cTkVector<cGcInventoryTechProbability> &lTechVector, eSizeType &leSizeType, bool &lbIsCool,
        const cTkSeed &lSeed);
    eShipClass GetShipClassFromSizeType(eSizeType leSizeType);
    float GetStatModifierFromInventory(eStatsType leStatType);
    int GetSubstanceSlotMaxStorage(const TkID<128> &lSubstance);
    int GetTechGroupCount(const TkID<256> &lGroup);
    void IncreaseCapacity(InventoryChoice leType, eShipClass leShipClass, int liAmount);
    void IncreaseDimsToSupportCapacity(InventoryChoice leType, eShipClass leShipClass);
    bool IsAtMaxCapacity(InventoryChoice leType, eShipClass leShipClass);
    bool IsSlotBlockedByBrokenTech(const cGcInventoryIndex &lIndex);
    bool IsSlotBroken(const cGcInventoryIndex &lIndex);
    bool IsValidLayoutPos(const cGcInventoryIndex &lIndex);
    void LoadFromContainer(const cGcInventoryContainer &lContainer, InventoryChoice leChoice);
    void PackageAllTech();
    void PopulateInventoryContainer(cGcInventoryContainer &lInventoryContainer);
    bool Remove(const cGcInventoryIndex &lIndex, int liAmountOverride);
    void RepairEntireInventory();
    void RepairSlot(const cGcInventoryIndex &lIndex);
    void SetCapacityFromGenerationData(
        const cGcInventoryLayoutGenerationDataEntry *lpGenerationEntry, InventoryChoice leType);
    void SetDimensionsFromGenerationData(
        const cGcInventoryLayoutGenerationDataEntry *lpGenerationEntry, InventoryChoice leType);
    void ValidateBrokenSlots(InventoryChoice leType);

    static void UpgradeInventoryChestContainerCapacity(
        cGcInventoryContainer &lStoredInventoryContainer, const cTkSeed &lSeed, int liNewCapacity, int liNewWidth,
        int liNewHeight);
    static eWeaponStatClass GetWeaponStatClassFromNode(TkHandle lNode);
    static eWeaponStatClass GetWeaponStatClassFromResource(TkStrongType<int, TkStrongTypeIDs::TkResHandleID> lResource);

    cTkBitArray<uint64_t, true, 16> mxValidSlots[16];
    int16_t miWidth;
    int16_t miHeight;
    int16_t miCapacity;
    cTkVector<cGcInventoryElement> mStore;
    cTkVector<cGcInventoryElement> mStoreHistory;
    cTkVector<cGcInventorySpecialSlot> maSpecialSlots;
    cTkVector<cGcInventoryBaseStatEntry> maBaseStats;
    cGcInventoryLayout mLayoutDescriptor;
    bool mbAutoMaxEnabled;
    bool mbIsCool;
    eInventoryStackSizeGroup meStackSizeGroup;
    cGcInventoryClass mClass;
    cTkFixedString<256, char> mInventoryName;
    cTkUnorderedMap<TkID<256>, int, TkIDUnorderedMap::Hash256> mTechGroupCounts;
};

SKYSCRAPER_END