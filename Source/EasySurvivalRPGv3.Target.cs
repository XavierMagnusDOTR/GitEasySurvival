// Easy Systems

using UnrealBuildTool;
using System.Collections.Generic;

public class EasySurvivalRPGv3Target : TargetRules
{
	public EasySurvivalRPGv3Target(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V2;

		ExtraModuleNames.AddRange( new string[] { "EasySurvivalRPGv3" } );
	}
}
