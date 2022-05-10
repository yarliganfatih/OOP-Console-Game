# OOP-Console-Game
It's a game that can be played via the CLI. It is our first project that we have coded according to OOP architecture.

```
 1 => Name : Volverine      Type : Warrior     HP : 141     Attack : 37      Defence : 24      Chance : 12      
 2 => Name : Sherman        Type : Warrior     HP : 219     Attack : 34      Defence : 28      Chance : 14      
 3 => Name : Pershing       Type : Warrior     HP : 212     Attack : 34      Defence : 25      Chance : 13      
 4 => Name : Chaffee        Type : Warrior     HP : 131     Attack : 37      Defence : 21      Chance : 15      
 5 => Name : Patton         Type : Warrior     HP : 245     Attack : 32      Defence : 27      Chance : 12      
 6 => Name : Jackson        Type : Warrior     HP : 241     Attack : 34      Defence : 22      Chance : 13      
 7 => Name : Hellcat        Type : Warrior     HP : 242     Attack : 32      Defence : 21      Chance : 12      
 8 => Name : Stuart         Type : Defender    HP : 518     Attack : 30      Defence : 57      Chance : 10      
 9 => Name : Hetzer         Type : Defender    HP : 371     Attack : 33      Defence : 59      Chance : 11      


 ...


28 => Name : Chaffee        Type : Healer      HP : 123     Attack : 16      Defence : 26      Chance : 16
-------------------------------------------------------------------------------------------------------------------
Please select first team : 1 2 3 4
-------------------------------------------------------------------------------------------------------------------
Please select second team : 5 6 7 4
4 can not use, Select again 
Please select second team : 8 7 6 5
-------------------------------------------------------------------------------------------------------------------
The battle will be played on : Casual
Team 1 with attack order :
 1 => Name : Volverine      Type : Warrior     HP : 141     Attack : 37      Defence : 24      Chance : 12
 2 => Name : Sherman        Type : Warrior     HP : 219     Attack : 34      Defence : 28      Chance : 14
 3 => Name : Pershing       Type : Warrior     HP : 212     Attack : 34      Defence : 25      Chance : 13
 4 => Name : Chaffee        Type : Warrior     HP : 131     Attack : 37      Defence : 21      Chance : 15
Team 2 with attack order :
 1 => Name : Stuart         Type : Defender    HP : 518     Attack : 30      Defence : 57      Chance : 10
 2 => Name : Hellcat        Type : Warrior     HP : 242     Attack : 32      Defence : 21      Chance : 12
 3 => Name : Jackson        Type : Warrior     HP : 241     Attack : 34      Defence : 22      Chance : 13
 4 => Name : Patton         Type : Warrior     HP : 245     Attack : 32      Defence : 27      Chance : 12
-------------------------------------------------- BATTLE STARTS --------------------------------------------------
Team 2 starts the battle !!
================================================== ROUND 1 ==================================================
Team 2 :
 1 => Name : Stuart         Type : Defender    Current HP : 518
 2 => Name : Hellcat        Type : Warrior     Current HP : 242
 3 => Name : Jackson        Type : Warrior     Current HP : 241
 4 => Name : Patton         Type : Warrior     Current HP : 245
Team 1 :
 1 => Name : Volverine      Type : Warrior     Current HP : 141
 2 => Name : Sherman        Type : Warrior     Current HP : 219
 3 => Name : Pershing       Type : Warrior     Current HP : 212
 4 => Name : Chaffee        Type : Warrior     Current HP : 131

Stuart will attack! Select an opponent from Team 1 to attack : 1
Stuart attacted to Volverine Damage : 24

Volverine will attack! Select an opponent from Team 2 to attack : 1
Volverine attacted to Stuart Damage : 23


...


Pershing will attack! Select an opponent from Team 2 to attack : 4
Pershing attacted to Patton Damage : 26
================================================== ROUND 29 ==================================================
Team 2 :
 1 => Name : Stuart         Type : Defender    Current HP : 386
 4 => Name : Patton         Type : Warrior     Current HP : 54
Team 1 :
 3 => Name : Pershing       Type : Warrior     Current HP : 10

Stuart will attack! Select an opponent from Team 1 to attack : 4
Please select again : 3
Pershing is dead !!!
Stuart attacted to Pershing Damage : 24
==================================================== GAME OVER ====================================================
||                                                                                                               ||
||                                                Team 2 Wins !!!                                                ||
||                                                                                                               ||
===================================================================================================================
```