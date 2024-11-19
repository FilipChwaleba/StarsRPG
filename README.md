# Stars RPG 

## Classes
 - <b>Unveiler</b> / Rouge - speed, attack
 - <b>Justiciar</b> / Warrior - defence, hp
 - <b>Interlacer</b> /Wizard - attunment, energy
 - <b>Oracle</b> / Cleric - support/healing, stamina

### Stats (primary)
 - <b>Attack</b> - increase Weapon Damage, primary multiplier
 - <b>Defense</b> - decrease Weapon damage taken by a percantege, based on this
 ============================================================
 - <b>Attunment</b> - incease Elemental Damage, primary multiplier
 - <b>Warding</b> - decrease Elemental Damage taken by a percantege, based on this
 ============================================================
 - <b>HitPoints</b> - how much Damage you can take before Fainting
 - <b>Speed</b> - increase how often you take Action, and how high your Initial Action Order is
============================================================
 - <b>Crit Damage</b> - increase all Critical Damage dealt
 - <b>Crit Rate</b> - increase the chance for all [non-DoT and non-Hazard DMG] to Crit 
 


#### Stats (additional)

- <b>Resistance</b> - reduce damage taken, based if damage/enemy is <b>Luminous, Astral, or Entropic</b>
============================================================
 - <b>Precision</b> - increase the chance to land an Attack
 - <b>Evasion</b> - decrease the chance of being hit by an Attack
 ============================================================
 - <b>Focus</b> - increase the chance to Apply a Debuff 
 - <b>Tenacity</b> - decrease the chance to Be Applied with a Debuff
 ============================================================
 - <b>DMG Bonus</b> - multiplicatively increase all Elemental Damage dealt
 ============================================================
 - <b>Energy Regen Rate</b> - increase the ammount of Energy gained when restoring Energy
 - <b>Energy Capacity</b> - how much Energy does your Ultimate cost
 ============================================================
 - <b>Stamina Regen Rate</b> - increase the ammount of Energy gained when restoring Stamina
 - <b>Stamina Capacity</b> - how much Stamina you can Carry
 ============================================================


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
- Shatter - deals medium Ice Damage. If the Target is currently Frozen, dispell the effects
            and deal a high instance of Ice Damage in Blast(aoe)
- Sublimate - 

<a name = "water"></a>

##### Water
  Core identity: Ultimate's, Stamina and Energy Restoration and Exchange 
- Passive : Fluidity - 
- Torrent - 
- Scald - 
- Wellspring - 
- Flux - 


<a name = "earth"></a>

##### Earth
  Core identity: Increased Aggro, Overshield creation and destruction, 'Defence through Offence'
 - Passive : Unyielding - 
 - Impale - 
 - Stabilize - 
 - Fracture - 
 - Quake - 

<a name = "steel"></a>

##### Steel
  Core identity: Tank, Defence Manipulation, Team Protection
- Passive : Ironclad - 
- Refine - 
- Snare - 
- Adamant - 
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