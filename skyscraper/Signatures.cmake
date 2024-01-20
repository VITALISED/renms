add_library(skyscraper_definitions INTERFACE)

target_compile_definitions(
    skyscraper_definitions
    INTERFACE
        D_cGcApplicationGameModeSelectorState_SystemCleanUp_PreparePhase_Signature="48 89 5C 24 08 48 89 74 24 10 57 48 83 EC ? 48 8B 3D ? ? ? ? 33 F6 0F 28 05 ? ? ? ?"
)
