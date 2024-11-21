# Stars RPG 

## Classes
 - <b>Unveiler</b> / Rouge - speed, attack
 - <b>Justiciar</b> / Warrior - defence, hp
 - <b>Interlacer</b> /Wizard - attunment, energy
 - <b>Oracle</b> / Cleric - support/healing, stamina

### Stats (primary)
 - <b>Attack</b> - increase Weapon Damage, primary multiplier
 - <b>Defense</b> - decrease Weapon damage taken by a percantege, based on this
 ========================================================
 - <b>Attunment</b> - incease Elemental Damage, primary multiplier
 - <b>Warding</b> - decrease Elemental Damage taken by a percantege, based on this
 ========================================================
 - <b>HitPoints</b> - how much Damage you can take before Fainting
 - <b>Speed</b> - increase how often you take Action, and how high your Initial Action Order is
========================================================
 - <b>Crit Damage</b> - increase all Critical Damage dealt
 - <b>Crit Rate</b> - increase the chance for all [non-DoT and non-Hazard DMG] to Crit 
 


#### Stats (additional)

- <b>Resistance</b> - reduce damage taken, based if damage/enemy is <b>Luminous, Astral, or Entropic</b>
========================================================
 - <b>Precision</b> - increase the chance to land an Attack
 - <b>Evasion</b> - decrease the chance of being hit by an Attack
 ========================================================
 - <b>Focus</b> - increase the chance to Apply a Debuff 
 - <b>Tenacity</b> - decrease the chance to Be Applied with a Debuff
 ========================================================
 - <b>DMG Bonus</b> - multiplicatively increase all Elemental Damage dealt
 - <b>[element]DMG Bonus</b> - same as above, applied only to a Single Element
 ========================================================
 - <b>Energy Regen Rate</b> - increase the ammount of Energy gained when restoring Energy
 - <b>Energy Capacity</b> - how much Energy does your Ultimate cost (constant)
 ========================================================
 - <b>Stamina Regen Rate</b> - increase the ammount of Energy gained when restoring Stamina
 - <b>Stamina Capacity</b> - how much Stamina you can Carry
 ========================================================


NOTATKA - PRZEROBIĆ SYSTEM EFFECT NA BAZOWĄ KLASE DLA BUFF I DEBUFF

## Gameplay Loop
 - Turn Based RPG
 - Exploration Instance-Based Map, multiple location's, puzzle solving (certain Elements needed to complete puzzle)
 - Character Trust System: influence Current Story Branch
  - - gain access to Powerful and Rare gear tied to Characters/Locations/Events
  - - gain <b>Luminous/Astral/Entropic </b> type points for Elemental Skill Tree
  - - explore Character Storyline and Development Arcs
  - - unlock Character Subclasses/Diffirent Elements for them
 

## Systems
##### Battle System =>> Basic Combat Flow
 - Battle System -> Action Order
 - Battle System -> Enviromental Hazards
 - Battle System -> Action Types : Standard, Ultimate, Items, End Action
==================================|
##### Equipment System =>> Equip Armor and Weaponry
 - Equipment System -> Purchase Items from Shops/Vendors
 - Equipment System -> Inventory for Materials and Gear
 - Equipment System -> Conusmables
 
==================================|
##### Leveling System
 - gain stats per levelUp, ammount based on Class
 - gain abillity levelUps on certain Level BreakPoints
 - gain additional Passives, based on certain Level BreakPoints


==================================|
##### Elemental System =>> Implementation for all Damage dealt
 - Elemental System -> Elemental Keywords 
 - Elemental System -> Damage Type Resistance
 - Elemental System -> Global Skill Tree

==================================|
 ##### Elemental Skill Tree
 - Primary Path of Character and Party Progression
 - Spend Points gained on chosen Tree's, to unlock passive benefits, unlock additional keywords, improve already existing effects, or allow for new puzzle solving tools
 - Limited Point Pool, forcing player to make UNCHANGABLE choices on which skill tree to level up
 - Most Points will be universal, and will be able to be spend on Every Skill Tree
 - Some Points will be of a Specific Type, and will be spendable only in a designated Skill Tree

 - You can reset which Perks are selected on the Tree, but not how many points have been allocated to each tree




 ## Elements : 
 ### Luminous
 - Simple, easy to understand
 - Stays true to it's nature
 - Unchanging/Everchanging, but never both
 - A Phenomenon that we can meet in the real  world, 
 - Thier Constellations appear when the Elements are in close proximity or in great concentration
 - Symbol outline - Triangle

 #### List : 
 - [Ice](#ice)  
 - [Water](#water)
 - [Earth](#earth)
 - [Electric](#electric)
 - [Steel](#steel)
 - [Nature](#nature)
 - [Sand](#sand)


 ### Astral
- Tied to Emotion, States of Heart, and Belief
- Shifting, and Changing, due to our Perception
- Embodied in Acts of the People and Beings of the World, can be met in nature in certain circumstances
- Their Constellations are rarely visible, due to the need of almost perfect attunement of your Emotional State to the Element. If succesfull, the Constelation is visible from anywhere. In distinct area's overfilled with a certain type of emotion, the Constellation is visible
- Symbol outline - Circle

#### List : 
- [Fire](#fire)
- [Shadow](#shadow)
- [Nightmare](#nightmare)
- [Light](#light)
- [Poison](#poison)
- [Wind](#wind)
- [Blood](#blood)


 ### Entropic
 - Very Complex and Difficult to Percieve, Some are unexplainable to the human mind
- Warp the Fabric of the Universe 
- Enforcers of Order, when used by Great Beings, or Harbingers of Chaos
- Rarely Encountered out in Nature, more often in places of Great Power, or where a being wielding these forces Resides
- Their Constellations are always visible in the sky, as the inner workings of these Elements are ever-present in the Universe. Despite that, rarely anyone can attune with them
- Symbol outline - Triangle + Circle

### List : 
- [Void](#void)
- [Imaginary](#imaginary)
- [Quantum](#quantum)
- [Spirit](#spirit)
- [Fission](#fission)
- [Eclipse](#eclispe)


<b>=================================================</b>

<b>=================================================</b>


## Keywords and Elements
### Luminous

<a name = "ice"></a>

##### Ice  
  Core identity: Focus, Action Prevention, Debuff Application
- Passive : Frostbite - gain additional Focus based on level.
                        Whenever you deal Ice damage, there is a small chance to apply 
                        Freeze to them, per hit
- Frozen - a target cannot perform any Actions in their next turn, ending it automatically
          The state ends at the beggining of next Action Cycle.
          While Frozen, units take reduced Damamge
- Hail - create a Hazard -> create an Ice Storm, dealing a small ammount of Ice Damage
        whenever a unit begins their turn. This damage has a seperate chance to freeze a target
- Shatter - deals medium Ice Damage. If the Target is currently Frozen, dispell the effect
            and deal a high instance of Ice Damage to the target and nearby Targets (Blast)
- Sublimate - Inflicts a single Target with Sublimate. Whenever they are attacked by any Entity,
              they gain a stack of Sublimate, decreasing their Tenacity. At 4 stacks, the next
               debuff applied is guarenteed to be applied, ignoring any Resistances to it

<a name = "water"></a>

##### Water
  Core identity: Ultimate's, Stamina and Energy Restoration and Exchange 
- Passive : Fluidity - Once per Turn, you can convert a portion of your Stamina into Energy (Ebb), or vice versa (Flow). Gain increased Stamina Capacity, based on Energy Regen Rate.
  Ultimate abillities now cost Stamina and Energy
- Torrent - create a Hazard -> summon a Rainstorm, dealing light Water Damage at the beginning
            of every Foe's Turn; also restore a small percentage of Energy or Stamina for all allies, whichever is currently lower. Lasts 4 turn
- Scald - gain a Damage bonus based on your Total Energy + Total Stamina, but your every action
          now drains a portion of those Rescources. This bonus is doubled for Ultimate Damage
          Lasts 3 turns
- Wellspring - mark a Target with Wellspring. When they die, cause a big splash of water, dealing light Water damage to nearby targets (Blast), and restoring a portion of Missing Stamina and Energy to the Unit that killed the initial Target. Killing Elite Targets restores
Stamina and Energy to all allies. When the Target is defeated with an Ultimate, the effects
trigger twice, at increased Efficiency
- Flux - buff -> reduce the Energy (and Stamina for Water)cost by 15%, and increase Ultimate
                Damage by 20%. Reduce Speed by 15% Lasts 2 turns 


<a name = "earth"></a>

##### Earth
  Core identity: Increased Aggro, Overshield creation and destruction, 'Defence through Offence'
 - Passive : Unyielding - At the start of your turn, generate a small ammount of personal Overshielding. Whenever you have an Overshield, enemy Units are more likely to Attack you
 - Impale - create a cluster of Rock Spikes, dealing medium Earth Damage to a single enemy, and apply a stack of Impale, lasting for 4 turns. Debuff->  Applying additional stacks won't refresh the duration. When Impale ends, the target takes a portion of the initial Damage of the Keyword again, and all allies receive an Overshield. The Strength of the Damage and Shield are based on Impale Stacks. 
 - Stabilize - a buff-> grant medium size Overshield to a single ally. Whenever enemies attack them, they receive stacks of Impale. Shield duration 3 turns  
 - Fracture - a buff -> whenever you or any ally have their Overshield destroyed, deal a Medium ammount of Earth damage back to the attacker. This effect has a chance to trigger Impale, and deals double damage to targets that have Overshields
 - Quake - deal a Small ammount of Earth damage to all enemies (AoE). Whenever they posses any Impale stacks, consume each stack and deal a set ammount of Earth Damage to them. Each Damage instance gains a %Damage Bonus, based on your current Overshield

<a name = "electric"></a>
##### Electric
  
  Core identity : Speed, multiple actions per Cycle, 'Conserving Momentum'
- Passive : Amplify - Whenever you land an Attack on an enemy, gain a Stack of Aplified
        buff -> Each Stack of Amplified grants you increased Speed. At max Stacks, you are guarenteed to take Action at the end of the Action Order. Defeating enemies grants 2 stacks. Getting hit with an Attack depletes 2 stacks. Lasts 2 turns, afterward each turn loose 1 stack of Amplify until you strike a Target again
- Jolt - a debuff -> hitting the affected Target spreads chain lightning to other nearby Targets, dealing medium Electric Damage to them. Lasts 2 turns
- Dynamo - a buff -> increase the affected Unit's Speed by a percentage. Whenever Amplify reaches max stacks, refresh Dynamo's duration and gain an Electric Damage% Bonus, based on your current Speed. Lasts 3 turns
- Galvanize - a buff -> whenever an Enemy hits you, deal a small ammount of Electric Damage to them. If they dispell any number of Amplified stacks during said Attack, the damage dealt increases in proportion to the stacks lost, and their Attack is also Lowered for 2 turns. Buff duration 3 turns
- Voltage - deal medium Electric Damage to a Target and other nearby Targets (Blast). If you currently have 5 stacks of Amplified, an Electrical Current surrounds you, procing this effect again every time your Action begins. Lasts for 3 turns or when all stacks of Amplified are lost




<a name = "steel"></a>

##### Steel
  Core identity: Tank, Defence Manipulation, Team Protection
- Passive : Ironclad - Increase Defence and Warding gained from all sources by a percentage, based on Level. When an Action Cycle begins, restore a small ammount of Health based on Defence or Warding, whichever is currently higher 
- Refine - 
- Snare - a debuff -> the affected Target is slowed. Whenever they take damage while affected by this Keyword, they loose all Overshields they currently possess. This effect is applied in Blast. Lasts 2 turns
- Adamant - a buff -> increase Defence by a medium ammount, and lower Warding by that same ammount. When an Enemy attacks you for the first time, based on the type of Damage they dealt to you, deal either Physical or Steel Damage back to them, based on Defence or Warding, respectively. If the Effect deals Steel Damage, swap the Warding and Defence changes, and if it deals Physical Damage, revert to original state. Lasts 3 turns
- Corrode - 

<a name = "nature"></a>

##### Nature
  Core identity: Stamina Economy, Consume HP to Restore/Ignore Stamina
- Passive : Bloom - 
- Sap -  
- Sprout-
- Blossom -
- Overgrowth -  

<a name = "sand"></a>

##### Sand
  Core identity: Missing Attacks, Increased Tenacity, Proactive Defence
 - Passive : Conceal - 
 - Mirage - 
 - Squall - 
 - Sink - 

<b>=================================================</b>

### Astral

<a name = "fire"></a>

##### Fire
  Core identity : Extended Combat, Self-sustain, Explosions
  - Passive : Heat - 
  - Scorch - 
  - Radiant - 
  - Ignite - 
  - Zeal - 

<a name = "shadow"></a>

##### Shadow
  Core identity : Disrupt Enemies, Dodge Attacks, Crit Rate 
  - Passive : Wraith - 
  - Engulf - 
  - Lurk - 
  - Obscure - 
  - Veiled - 

<a name= "nightmare"></a>

##### Nightmare
  Core identity : High AoE Damage, Spread debuffs upon Death
  - Passive : Torment - 
  - Miasma - 
  - Macabre - 
  - Dread - 
  - Apparition - 

<a name = "light"></a>

##### Light
  Core identity : Support, Healing, Debuff Cleansing
  - Passive : Coalescence - 
  - Enlighten - 
  - Consecrate - 
  - Oath - 
  - Illuminate - 
<a name = "poison"></a>

##### Poison
  Core identity : Damage Over Time, Increase/Decrease Healing received
  - Passive : Devour - 
  - Accidate - 
  - Essence - 
  - Decay - 
  - Dissolve - 
<a name = "wind"></a>

##### Wind
  Core identity : Action Order Manipulation/Advance
  - Passive : U-Turn - 
  - Wind Shear - 
  - Vortex - 
  - Tailwind - 
  - Gale - 
<a name = "blood"></a>

##### Blood
  Core identity : Convert Energy into HP, use HP as a Rescource, heal and loose HP
  - Passive : Rot - 
  - Overheal - 
  - Ferocity - 
  - Rage - 
  - Garrote - 

  <b>=================================================</b>

  ### Entropic

  <a name = "void"></a>

  ##### Void
   Core identity : Abillity Suppression, Abillity Augmentation, Stat Buff Nullification
   - Passive : - Potential - 
   - - Potential -> Accretion
   - - Potential -> Anomaly
   - - Potentail -> Singularity
   - Silence - 
   - Disperse - 
   - Volatile - 
   - Nullify - 

  <a name = "imaginary"></a>

 ##### Imaginary
  Core identity : Randomness, Debuff Accumulation, Keyword Self-Procing/ Chain Reaction effects
   - Passive : Inspiration - 
   - Dazzle - 
   - Spectrum - 
   - Partition - 
   - Paragon
  <a name = "quantum"></a>

 ##### Quantum
  Core identity : Action Type Prevention, Control, Linking Targets
  - Passive : Enforce - 
  - Entangle - 
  - Envelop - 
  - Entwind - 
  - Terminate - 
  <a name = "spirit"></a>

 ##### Spirit
  Core identity : Single Target Damage, Precision, Crit Damage
  - Passive : Verity - 
  - Essence - 
  - Sunder - 
  - Zen - 
  - Mindstorm - 
  <a name = "fission"></a>

 ##### Fission
  Core identity : Constant Energy Consumption, Glass Cannon, Radioactive
  - Passive : Deconstruct - 
  - Assimilate - 
  - Feedback - 
  - Synthesize - 
  - Discharge - 
  <a name = "eclipse"></a>
 
 ##### Eclipse
 Core identity :  Reverse expected Result, Convert damage Dealt/Taken into Eclipse
  - Passvie : Echo - 
  - Dusk
  - Twiglight
  - Syzygy
  - Expunge
