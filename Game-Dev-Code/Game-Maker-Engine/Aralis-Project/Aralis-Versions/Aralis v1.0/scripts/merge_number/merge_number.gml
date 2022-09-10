/// @DnDAction : YoYo Games.Common.Function
/// @DnDVersion : 1
/// @DnDHash : 69532DFD
/// @DnDInput : 3
/// @DnDArgument : "funcName" "merge_number"
/// @DnDArgument : "arg" "argument0"
/// @DnDArgument : "arg_1" "argument1"
/// @DnDArgument : "arg_2" "argument2"
function merge_number(argument0, argument1, argument2) 
{
	/// @DnDAction : YoYo Games.Common.Execute_Code
	/// @DnDVersion : 1
	/// @DnDHash : 6102DF80
	/// @DnDParent : 69532DFD
	/// @DnDArgument : "code" "///@description merge_number$(13_10)///@arg num1$(13_10)///@arg num2$(13_10)///@arg amount$(13_10)$(13_10)var num1 = argument0;$(13_10)var num2 = argument1;$(13_10)var amount = argument2;$(13_10)$(13_10)var diff = num1 - num2;$(13_10)var merged = num1 - (diff * amount);$(13_10)$(13_10)return merged;"
	///@description merge_number
	///@arg num1
	///@arg num2
	///@arg amount
	
	var num1 = argument0;
	var num2 = argument1;
	var amount = argument2;
	
	var diff = num1 - num2;
	var merged = num1 - (diff * amount);
	
	return merged;
}