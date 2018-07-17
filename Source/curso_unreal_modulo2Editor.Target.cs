// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class curso_unreal_modulo2EditorTarget : TargetRules
{
	public curso_unreal_modulo2EditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;

		ExtraModuleNames.AddRange( new string[] { "curso_unreal_modulo2" } );
	}
}
