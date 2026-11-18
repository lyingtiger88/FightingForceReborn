using UnrealBuildTool;

public class FightingForceReborn : ModuleRules
{
    public FightingForceReborn(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        PublicDependencyModuleNames.AddRange(new[]
        {
            "Core", "CoreUObject", "Engine", "InputCore",
            "EnhancedInput", "AIModule", "NavigationSystem"
        });
    }
}
