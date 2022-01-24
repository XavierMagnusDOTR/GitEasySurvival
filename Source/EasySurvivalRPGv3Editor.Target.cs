// Easy Systems

using UnrealBuildTool;
using System.Collections.Generic;

public class EasySurvivalRPGv3EditorTarget : TargetRules
{
	public EasySurvivalRPGv3EditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V2;

		ExtraModuleNames.AddRange( new string[] { "EasySurvivalRPGv3" } );
	}
}
