#pragma once

enum class LevelSoundEvent : unsigned int {
    ItemUseOn,
    Hit,
    Step,
    Fly,
    Jump,
    Break,
    Place,
    HeavyStep,
    Gallop,
    Fall,
    Ambient,
    AmbientBaby,
    AmbientInWater,
    Breathe,
    Death,
    DeathInWater,
    DeathToZombie,
    Hurt,
    HurtInWater,
    Mad,
    Boost,
    Bow,
    SquishBig,
    SquishSmall,
    FallBig,
    FallSmall,
    Splash,
    Fizz,
    Flap,
    Swim,
    Drink,
    Eat,
    Takeoff,
    Shake,
    Plop,
    Land,
    Saddle,
    Armor,
    ArmorPlace,
    AddChest,
    Throw,
    Attack,
    AttackNoDamage,
    AttackStrong,
    Warn,
    Shear,
    Milk,
    Thunder,
    Explode,
    Fire,
    Ignite,
    Fuse,
    Stare,
    Spawn,
    Shoot,
    BreakBlock,
    Launch,
    Blast,
    LargeBlast,
    Twinkle,
    Remedy,
    Unfect,
    LevelUp,
    BowHit,
    BulletHit,
    ExtinguishFire,
    ItemFizz,
    ChestOpen,
    ChestClosed,
    ShulkerBoxOpen,
    ShulkerBoxClosed,
    EnderChestOpen,
    EnderChestClosed,
    PowerOn,
    PowerOff,
    Attach,
    Detach,
    Deny,
    Tripod,
    Pop,
    DropSlot,
    Note,
    Thorns,
    PistonIn,
    PistonOut,
    Portal,
    Water,
    LavaPop,
    Lava,
    Burp,
    BucketFillWater,
    BucketFillLava,
    BucketEmptyWater,
    BucketEmptyLava,
    EquipChain,
    EquipDiamond,
    EquipGeneric,
    EquipGold,
    EquipIron,
    EquipLeather,
    EquipElytra,
    Record13,
    RecordCat,
    RecordBlocks,
    RecordChirp,
    RecordFar,
    RecordMall,
    RecordMellohi,
    RecordStal,
    RecordStrad,
    RecordWard,
    Record11,
    RecordWait,
    RecordNull,
    Flop,
    GuardianCurse,
    MobWarning,
    MobWarningBaby,
    Teleport,
    ShulkerOpen,
    ShulkerClose,
    Haggle,
    HaggleYes,
    HaggleNo,
    HaggleIdle,
    ChorusGrow,
    ChorusDeath,
    Glass,
    PotionBrewed,
    CastSpell,
    PrepareAttackSpell,
    PrepareSummon,
    PrepareWololo,
    Fang,
    Charge,
    TakePicture,
    PlaceLeashKnot,
    BreakLeashKnot,
    AmbientGrowl,
    AmbientWhine,
    AmbientPant,
    AmbientPurr,
    AmbientPurreow,
    DeathMinVolume,
    DeathMidVolume,
    ImitateBlaze,
    ImitateCaveSpider,
    ImitateCreeper,
    ImitateElderGuardian,
    ImitateEnderDragon,
    ImitateEnderman,
    ImitateEndermite,
    ImitateEvocationIllager,
    ImitateGhast,
    ImitateHusk,
    ImitateIllusionIllager,
    ImitateMagmaCube,
    ImitatePolarBear,
    ImitateShulker,
    ImitateSilverfish,
    ImitateSkeleton,
    ImitateSlime,
    ImitateSpider,
    ImitateStray,
    ImitateVex,
    ImitateVindicationIllager,
    ImitateWitch,
    ImitateWither,
    ImitateWitherSkeleton,
    ImitateWolf,
    ImitateZombie,
    ImitateZombiePigman,
    ImitateZombieVillager,
    EnderEyePlaced,
    EndPortalCreated,
    AnvilUse,
    BottleDragonBreath,
    PortalTravel,
    TridentHit,
    TridentReturn,
    TridentRiptide_1,
    TridentRiptide_2,
    TridentRiptide_3,
    TridentThrow,
    TridentThunder,
    TridentHitGround,
    Default,
    FletchingTableUse,
    ElemConstructOpen,
    IceBombHit,
    BalloonPop,
    LTReactionIceBomb,
    LTReactionBleach,
    LTReactionElephantToothpaste,
    LTReactionElephantToothpaste2,
    LTReactionGlowStick,
    LTReactionGlowStick2,
    LTReactionLuminol,
    LTReactionSalt,
    LTReactionFertilizer,
    LTReactionFireball,
    LTReactionMagnesiumSalt,
    LTReactionMiscFire,
    LTReactionFire,
    LTReactionMiscExplosion,
    LTReactionMiscMystical,
    LTReactionMiscMystical2,
    LTReactionProduct,
    SparklerUse,
    GlowStickUse,
    SparklerActive,
    ConvertToDrowned,
    BucketFillFish,
    BucketEmptyFish,
    BubbleColumnUpwards,
    BubbleColumnDownwards,
    BubblePop,
    BubbleUpInside,
    BubbleDownInside,
    HurtBaby,
    DeathBaby,
    StepBaby,
    SpawnBaby,
    Born,
    TurtleEggBreak,
    TurtleEggCrack,
    TurtleEggHatched,
    LayEgg,
    TurtleEggAttacked,
    BeaconActivate,
    BeaconAmbient,
    BeaconDeactivate,
    BeaconPower,
    ConduitActivate,
    ConduitAmbient,
    ConduitAttack,
    ConduitDeactivate,
    ConduitShort,
    Swoop,
    BambooSaplingPlace,
    PreSneeze,
    Sneeze,
    AmbientTame,
    Scared,
    ScaffoldingClimb,
    CrossbowLoadingStart,
    CrossbowLoadingMiddle,
    CrossbowLoadingEnd,
    CrossbowShoot,
    CrossbowQuickChargeStart,
    CrossbowQuickChargeMiddle,
    CrossbowQuickChargeEnd,
    AmbientAggressive,
    AmbientWorried,
    CantBreed,
    ShieldBlock,
    LecternBookPlace,
    GrindstoneUse,
    Bell,
    CampfireCrackle,
    SweetBerryBushHurt = 262,
    SweetBerryBushPick,
    Roar = 260,
    Stun,
    CartographyTableUse = 264,
    StonecutterUse,
    ComposterEmpty,
    ComposterFill,
    ComposterFillLayer,
    ComposterReady,
    BarrelOpen,
    BarrelClose,
    RaidHorn,
    LoomUse,
    AmbientInRaid,
    UICartographyTableUse,
    UIStonecutterUse,
    UILoomUse,
    SmokerUse,
    BlastFurnaceUse,
    SmithingTableUse,
    Screech,
    Sleep,
    FurnaceUse,
    MooshroomConvert,
    MilkSuspiciously,
    Celebrate,
    JumpPrevent,
    AmbientPollinate,
    BeehiveDrip,
    BeehiveEnter,
    BeehiveExit,
    BeehiveWork,
    BeehiveShear,
    HoneybottleDrink,
    Undefined
};

enum class LevelEvent : short {
    Undefined,
    SoundClick = 1000,
    SoundClickFail,
    SoundLaunch,
    SoundOpenDoor,
    SoundFizz,
    SoundFuse,
    SoundPlayRecording,
    SoundGhastWarning,
    SoundGhastFireball,
    SoundBlazeFireball,
    SoundZombieWoodenDoor,
    SoundZombieDoorCrash = 1012,
    SoundZombieInfected = 1016,
    SoundZombieConverted,
    SoundEndermanTeleport,
    SoundAnvilBroken = 1020,
    SoundAnvilUsed,
    SoundAnvilLand,
    SoundInfinityArrowPickup = 1030,
    SoundTeleportEnderPearl = 1032,
    SoundAddItem = 1040,
    SoundItemFrameBreak,
    SoundItemFramePlace,
    SoundItemFrameRemoveItem,
    SoundItemFrameRotateItem,
    SoundExperienceOrbPickup = 1051,
    SoundTotemUsed,
    SoundArmorStandBreak = 1060,
    SoundArmorStandHit,
    SoundArmorStandLand,
    SoundArmorStandPlace,
    ParticlesShoot = 2000,
    ParticlesDestroyBlock,
    ParticlesPotionSplash,
    ParticlesEyeOfEnderDeath,
    ParticlesMobBlockSpawn,
    ParticleCropGrowth,
    ParticleSoundGuardianGhost,
    ParticleDeathSmoke,
    ParticleDenyBlock,
    ParticleGenericSpawn,
    ParticlesDragonEgg,
    ParticlesCropEaten,
    ParticlesCrit,
    ParticlesTeleport,
    ParticlesCrackBlock,
    ParticlesBubble,
    ParticlesEvaporate,
    ParticlesDestroyArmorStand,
    ParticlesBreakingEgg,
    ParticleDestroyEgg,
    ParticlesEvaporateWater,
    ParticlesDestroyBlockNoSound,
    ParticlesKnockbackRoar,
    ParticlesTeleportTrail,
    ParticlesPointCloud,
    ParticlesExplosion,
    ParticlesBlockExplosion,
    StartRaining = 3001,
    StartThunderstorm,
    StopRaining,
    StopThunderstorm,
    GlobalPause,
    SimTimeStep,
    SimTimeScale,
    ActivateBlock = 3500,
    CauldronExplode,
    CauldronDyeArmor,
    CauldronCleanArmor,
    CauldronFillPotion,
    CauldronTakePotion,
    CauldronFillWater,
    CauldronTakeWater,
    CauldronAddDye,
    CauldronCleanBanner,
    CauldronFlush,
    AgentSpawnEffect,
    CauldronFillLava,
    CauldronTakeLava,
    StartBlockCracking = 3600,
    StopBlockCracking,
    UpdateBlockCracking,
    AllPlayersSleeping = 9800,
    JumpPrevented = 9810,
    ParticleLegacyEvent = 16384
};