// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class tuto_udemy_modulo_2EditorTarget : TargetRules
{
	public tuto_udemy_modulo_2EditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;

		ExtraModuleNames.AddRange( new string[] { "tuto_udemy_modulo_2" } );
	}
}
