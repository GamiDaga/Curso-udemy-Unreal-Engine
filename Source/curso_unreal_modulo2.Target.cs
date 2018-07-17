// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class curso_unreal_modulo2Target : TargetRules
{
	public curso_unreal_modulo2Target(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;

		ExtraModuleNames.AddRange( new string[] { "curso_unreal_modulo2" } );
	}
}
