// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class tuto_udemy_modulo_2Target : TargetRules
{
	public tuto_udemy_modulo_2Target(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;

		ExtraModuleNames.AddRange( new string[] { "tuto_udemy_modulo_2" } );
	}
}
