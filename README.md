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
 - <b>Attunment</b> - increase Elemental Damage, primary multiplier
 - <b>Warding</b> - decrease Elemental Damage taken by a percantege, based on this
 ========================================================
 - <b>HitPoints</b> - how much Damage you can take before Fainting
 - <b>Speed</b> - increase how often you take Action, and how high your Initial Action Order is
========================================================
 - <b>Energy</b> - when this is full, you can cast your Ultimate abillity. Afterwards, it is set to 0. Energy is generated when performing any action in combat outside of using items
 - <b>Stamina</b> - rescource used to cast Skills. Restores a set ammount at the start of a Turn, using Basic Attacks also restores this.
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
 - <b>Stamina Regen Rate</b> - increase the ammount of Stamina gained when restoring Stamina
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
            of every Foe's Turn; also restore a small percentage of Energy or Stamina for all allies, whichever is currently lower. Lasts 4 turn or when a new Hazard is created
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
- Refine - a buff -> the Target ally gain an Overshield, based on the whole Party's Defence, if the Target wields a Luminous Element, or Warding for an Astral Element. Then, all other allies gain a small increase in their Defence or Warding, based on thier Element 
- Snare - a debuff -> the affected Target is slowed. Whenever they take damage while affected by this Keyword, they loose all Overshields they currently possess. This effect is applied in Blast. Lasts 2 turns
- Adamant - a buff -> increase Defence by a medium ammount, and lower Warding by that same ammount. When an Enemy attacks you for the first time, based on the type of Damage they dealt to you, deal either Physical or Steel Damage back to them, based on Defence or Warding, respectively. If the Effect deals Steel Damage, swap the Warding and Defence changes, and if it deals Physical Damage, keep the original state. Lasts 3 turns
- Corrode - a debuff -> shred a small percantage of the Target's Defence or Warding, based on their Element. After the Keyword ends, a percantage of all the Damage the Target has received will be dealt to them again; that percentage is based on the Diffirence between your and their Defence/Warding (does not matter whose diffirence is higher). If the Diffirence is higher than 35%, the Defence/Warding shred grows and lasts until the battle ends. Otherwise, lasts 3 turns
<a name = "nature"></a>
//slight rework needed
##### Nature
  Core identity: Stamina Economy, Consume HP to Restore/Ignore Stamina
- Passive : Bloom - 
- Sap -  
- Sprout-
- Blossom -
- Overgrowth -  

<a name = "sand"></a>
//additional keyword needed
##### Sand
  Core identity: Missing Attacks, Increased Tenacity, Proactive Defence
 - Passive : Conceal - Every time an enemy Target misses an Attack, or fails to deal damage to an allied Target (damage dealt = 0) that has received buffs from you, gain a stack of Conceal. At 6 stacks grant a Single allied Target the Vanish status
 -  - Vanish - an Effect -> negate all damage taken, and resist all debuffs application. Lasts until the end of the current Action Cycle
 - Mirage - a buff -> increase ally Target Tenacity by a percentage. While this Keyword lasts, ally Evasion now increases based on their current Tenacity, up to a limit. Lasts 3 turns
 - Squall - a debuff -> deal a small ammount of Single Target Sand Damage, and reduce the Targets Precision by a percentage based on Level. Additional Stacks increase damage dealt and reduce Precision further Stacks up to 5 times, lasts 2 turns.
 - Sink - a dubeff -> deal a small ammount Sand Damage at the start of the Targets turn. Whenever they don't launch an Attack, or don't deal any Damage, this Keyword gains a stack and the Targets Action Cycle Order is lowered. If the enemy happens to become the last Unit in the Action Cycle, deal an instance of High Blast Sand Damage to them and end this Keyword immidietly. Stacks 10 times, lasts 4 turns.
 - Sandstorm - create a Hazard -> at the beginning of the Action cycle, apply all enemies with a stack of Squall. Whenever anyone on the battlefield misses an Attack, this Hazard's action is progressed forward, from the last position of the current Action Cycle. When this Hazard takes action, it will apply all enemies with Squall again. Lasts 4 turns, or until a new Hazard has been created

<b>=================================================</b>

### Astral

<a name = "fire"></a>

##### Fire
  Core identity : Extended Combat, Self-sustain, Explosions
  - Passive : Heat - a buff -> when the Units Stamina reaches below 20%, grants them 1 stack of Heat. While Heat is active, the Unit gains a Damage Buff based on their Level and Base Attack, and also recovers Stamina when Attacks strike Targets. Each additional Stack double's the Stamina recovered. Max 3 stacks, new stacks refresh duration, lasts 2 turns.
  - Scorch - a DoT -> deal Fire Damage at the beginning of the Targets turn. Each stack increases the Damage of the Keyword. When you reach Max Stacks, end this effect and trigger Ignite(if locked, this will not trigger). Lasts 3 turns, new stacks refresh, max 5 Stacks
  - Radiant - a buff -> increase the Targets Attack and Attunement by a medium ammount. The Target and other nearby Targets gain 1 stack of Heat, even if they don't wield Fire. Lasts 2 turns.
  - Ignite - a damaging explosion dealing a Medium ammount of Fire Damage in Blast. This Damage partially ignores defensive Stats, and scales off of total Attack and Attunement. 
  - Zeal - a buff -> whenever any Ally performs an Attack, restore a small ammount of HP; there is a small chance for you to gain a stack of Heat. When a Target that posseses 3 stacks of Heat and Zeal dies, they revive with 50% of their Max HP. This can only occur once per battle, per Unit

<a name = "shadow"></a>

##### Shadow
  Core identity : Disrupt Enemies, Dodge Attacks, Crit Rate 
  - Passive : Wraith - gain additional Evasion, scaling with your Crit Rate. After successfully dodging an Attack, gain a boost to Crit DMG, based on level. Lasts 1 turns.
  - Engulf - a debuff -> the Target cannot Expend or Regenerate Energy or Stamina. Their Precision is also slightly lowered. Lasts 3 turns
  - Lurk - a buff -> when the Target's turn begins, forcefully end it immidietly. If thier HP does not decrease until their next Turn, gain a Large bonus to Crit Rate, lasting until you take Damage
  - Obscure - create a Hazard -> whenever an Enemy launches an Attack, there is a small chance for them to take a small ammount of Shadow Damage. If the Damage occurs, their next Attack is guarenteed to miss. Attacks agains Shadow type Units increase the chance of the Damage triggering. Lasts 3 turns or when a new Hazard is created
  - Veiled - a buff -> turn the Target Invisible : until they Take Damage or launch an Attack, they cannot be targeted by Attacks. Launching an Attack from this state guarentees the Attack to Critically Strike, and triggers Wraith if the Target wields the Shadow Element.

    Note - you can use Blast Attacks, AoE Attacks, DoT's and Hazards to end Veiled easily

<a name= "nightmare"></a>

##### Nightmare
  Core identity : High AoE Damage, Spread debuffs upon Death
  - Passive : Torment - Whenever a Target is hit with 2 instances of Nightmare Damage or Nightmare Debuffs, an explosion below them procs, dealing a Blast instance of Light Nightmare DMG. This effect has an Internal Cooldown of 1 turns per Target
  - Miasma - a debuff -> when the Target takes Ultimate or Nightmare Damage, detonate all stacks of this Keyword, dealing light Nightmare Damage, additional Stacks increse the Damage dealt. This Damage partially ignores Warding. Max 3 stacks, lasts 2 turns
  - Macabre - a debuff -> when the Target is defeated, they unleash an AoE explosion, dealing very Light Nightmare Damage. Then, spread all debuffs applied to the defeated Target to all other Hit Targets, and apply them a Stack of Miasma. No duration limit
  - Dread - a buff -> gain a Large bonus to Attunment, but decrease your Precision. While the buff lasts, all of your Attacks now deal an Additional instance of Nightmare Damage, based on Current Attunment and Level. Missing an Attack or taking Ulitmate Damage ends this Effect early. When this Keyword ends, a medium instance of Nightmare Damage is dealt to you. Lasts 3 turns 
  - Apparition - create a Dreadful Illusion on the Action Order, with base Speed and HP based on your Level. If the Illusion get's destroyed by Enemies, or when it's turn begins, it explodes, dealing Medium Nightmare AoE Damage. All Damaged Targets have a chance to be applied with a Nightmare Keyword; each Target hit increases this chance.

<a name = "light"></a>

##### Light
  Core identity : Support, Healing, Debuff Cleansing
  - Passive : Coalescence - when any ally if affected by a Light Keyword, they gain an Orb of Hope, recording all healing received, including overhealing. When the current Action Cycle ends, the Orb explodes, dealing Single Target Light Damage to the enemy with the highest current Health on-field
  - Enlighten - a buff -> whenever the buffed Target lands attacks they heal a small ammount of their Max HP and reduce this Keyword's stacks by 1. Starts with 8 stacks, each Target hit depletes a stack. Lasts 4 turns 
  - Consecrate - create a Hazard -> all allies can resist up to 3 debuff applications while this Hazard lasts. When a new Action Cycle begins, heal all allies for a moderate ammount, based on your Attunment. Lasts 3 turns, or when a new Hazard is created.
  - Oath - a buff -> restore a Medium ammount of Health to a single Target on the initial cast. At the beginning of the Targets turn the Heal is reapplied. If the healed Targets posseses any debuffs, cleanse the latest one applied and add a single turn to this Keywords duration. Lasts 3 turns, max 5 turns.
  - Illuminate - a debuff -> all Targets affected have their Precision and Attunement lowered. Whenever allies attack Targets affected by this Keyword, they restore a Moderate ammount of Health, per hit. When any enemy is defeated with this Keyword, is will spread to 1 unaffected Target. Lasts 2 turns.
<a name = "poison"></a>

##### Poison
  Core identity : Damage Over Time, Increase/Decrease Healing received
  - Passive : Devour - 
  - Accidate - 
  - Essence - 
  - Decay - 
  - Dissolve - 
<a name = "wind"></a>

Note - potrzeba Reworku Keywordów dla lepszej synergii między nimi

##### Wind
  Core identity : Action Order Manipulation/Advance
  - Passive : U-Turn - whenever you Advance an Ally's Action forward, or delay an Enemy's Action, gain a stack of U-Turn. At 4 stacks, swap two selected Units(ally or foe) position in the Action Order. That position is now locked, regardless of Speed changes, for 1 Action Cycle.
  - Wind Shear - a DoT -> deal light Wind Damage to a single Target. When the Keyword reaches Max Stacks, immidietly take Action and reduce the number of Stacks to 1. Max 5 stacks, new stacks refresh Duration, lasts 3 turns.
  - Vortex - create a Hazard -> at the Beginning and End of the Action Cycle, deal light Wind Damage to all Enemy Targets and heal all Allies by a small ammount. Whenever any Action gets Advanced or Delayed, that Advancment or Delay gets increased by 20%. Lasts 3 turns or when a new Hazard is created
  - Tailwind - a buff -> cause the Target to immidietly take Action and gain a Damage Bonus based on your Speed. This Keyword can affect the Same Target once every Action Cycle, and cannot affect the Caster. Damage buff lasts 1 turn.
  - Gale - a Blast explosion dealing medium Wind Damage. If any Targets hit have experienced any Action Advancment or Delay in this Action Cycle, this Keyword deals double Damage, and Advances your Action forward.

Note -> zmiana efektu Vortex na tworzenie Hazardu zamiast AoE explozji
<a name = "blood"></a>

##### Blood
  Core identity : Convert Energy into HP, use HP as a Rescource, heal and loose HP
  - Passive : Rot - Convert all of your Energy into Additonal Max HP; any additional Energy gained from any source is converted into healing. Every type of Action now costs HP to use instead of Energy or Stamina. Your Ultimate is now used with Stamina. HP to Energy conversion Ratio = 1:8. All of your attacks gain Lifesteal, based on your Level and Max HP
  - Overheal - a buff -> whenever any healing received surpasses your Max HP pool, the excess is converted into an Overshield. Whenever you gain an Overshield, restore a set ammount of Stamina. Overshield lasts until broken. Lasts 3 turns.
  - Ferocity - a debuff -> whenever a Target with this Keyword is defeated, the Unit that landed the Final Blow restores a percentage of their Max Stamina and have their Action Advanced.
  - Rage - a buff -> whenever you loose or gain HP, gain a stack of Rage. Each stack of Rage slightly increases your Attack and Defence. When your turn begins, loose 2 stacks of Rage. Max 25 stacks, lasts 1 turn (no need for duration as Stacks naturally fall-off)
  - Garrote - a debuff -> whenever the affected Target is hit, reduce their Action Order by 1. When their turn begins, they take Medium Single Target Blood Damage, each time any Unit took Action before them. This effect ends after the Damage triggers

  <b>=================================================</b>

  ### Entropic

  <a name = "void"></a>

  ##### Void
   Core identity : Abillity Suppression, Abillity Augmentation, Stat Buff Nullification
   - Passive : - Potential - Whenever anz Ally completes an Action, gain 1 stack of Potential. At 15 stacks, augment your next abillity, inflicting an Additional Effect, based on the abillities Target. Afterwards, reduce Potential stacks to 0
   - - Potential -> Accretion:
     - - - vs Enemies : create a dimensional Rip, dealing Medium AoE Void Damage to All Enemies. Non-Boss enemies below 15% HP have a chance to be Executed
     - - - vs Allies : create a Hazard -> conjure an Ergosphere, drastically increasing all Allies Speed and initially advancing their Action Forward, but draining a small ammount of Health from them at the beginning of their Turn. Lasts 2 turns, or until a new Hazard is created
   - - Potential -> Anomaly:
   - - - vs Enemies : deal light Void AoE Damage and apply them with the Anomaly Effect. Whenever Targets afflicted by Anomaly possess or gain Debuffs / Debuffing Keywords, that have stacks, the stack count is doubled. Also, being applied with any debuff will refresh ALL debuff's durations. Stacks cannot overcap (at base). Lasts 3 turns
   - - - vs Allies : the next Ally Target that you affect restores 100% of their Max Energy. You loose all of your Current Energy, and cannot gain Energy until the next Action Cycle.
   - - Potentail -> Singularity:
   - - - vs Enemies : the main Target of your next Attack gets applied with the Singularity Effect. Whenever any Enemy takes damage, the Target with Singularity takes a portion of that Damage again as Void Damage. Lasts 2 turns
   - - - vs Allies : the main Target of your next Action gets applied with the Nucleus Effect. Whenever any buffs are applied to Any Ally, the unit with The Effect also receives them. They also recover a small ammount of Energy at the start of their Turn. Lasts 3 turns 
   - Silence - a debuff -> prevent the Target from using their Ultimate and Skills. If they possess maximum Energy or Stamina, gain 1 stack of Potential. Lasts 1 turn
   - Disperse - a buff -> fashion a Void Shell for a single ally Target, blocking the next instance of Damage taken.
   - Volatile - a debuff -> create a Delayed Explosion on the Target. Depending on the Targets tier, the explosion will take additional Turns to Detonate (up to 3). Each turn spent charging will increase the Damage dealt. A maximum charge will grant 3 stacks of Potential
   - Nullify - an effect -> a random Stat (excluding HP, Energy and Stamina) will be 'Negated'. When a numerical(int) Stat is negated, they are set to their Base, while a percent% (float) Stat has it's value set to 0%. This Effect cannot be cleansed. Lasts 2 turns

  <a name = "imaginary"></a>

 ##### Imaginary
  Core identity : Randomness, Debuff Accumulation, Keyword Self-Procing/ Chain Reaction effects
   - Passive : Inspiration - whenever you or an ally apply a debuff to an enemy Target, gain a stack of Inspiation. Each stack increases your Focus and gives you a DMG% Bonus against debuffed Targets. At max Stacks, your next Attack will Strike ALL enemy Targets, and reduce Inspiration stacks to 0 afterwards.
   - Dazzle - a debuff -> an Instance of Single Target Imaginary Damage, decreasing Tenacity of the Target hit by a small ammount. For every debuff on the Target, there is a chance for this Keyword to trigger again, up to 3 times. Stacks up to 10 times, lasts 2 turns.
   - Spectrum - an effect -> after you attack a Target, you both enter the Rainbow Spectrum state. Whenever any of you take Action, a random color out of 7 will be selected for the both of you, giving you and your Linked Target positive or negative effects. This state can trigger up to 3 times, and ends early in any of you are Defeated.
   - Partition - an effect -> This Keyword function diffirently based on its Target. If it's an Enemy, convert their most recently received Buff into a Random Debuff. If it's an Ally, convert their most recently received Debuff into a Random Buff. There is a small chance for this Keyword to activate again.
   - Paragon - whenever you strike an Enemy that has an equal ammount of Debuffs to your current Buffs, enter the Paragon state : immidietly take Action again, your next Attack will deal a Portion of it's damage again. The additional Damage is dealt for the sum of all debuffs currently applied to all enemy Targets. Whenever a Target is hit with an Instance of Additional damage, dispel 1 debuff from them. The Paragon State ends when any Enemy Target looses all of its debuff or is defeated. The Paragon state can be entered once every 3 turns, after it ends
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
  - Passive : Verity - For every Precision above 100% convert it into additional Crit DMG. Whenever you land a Critical Hit, apply Verity to the Target. If any ally were to miss their Attack against a Target marked with Verity, consume Verity to guarentee the Attack to strike
  - Essence - a buff -> hitting Targets grants stacks of Essence, slightly increasing your Precision. Upon reaching max Stacks, your last attacked Target is applied with Verity automatically. Stacks are lost upon switching Targets. Max 6 stacks
  - Sunder - Deal an instance of Medium Single Target Spirit Damage. If the Target is affected by Verity, end it immidietly to deal a portion of that Damage again, and push them out of the current Action Cycle. 50% effective vs Bosses
  - Zen - a buff -> gain a small Attack bonus, but slightly decrease your Precision. If in the next 2 turns you don't miss any Attack, gain an additional Stack of this Keyword, refreshing its duration, and gaining a Large bonus to Attack and Precision. Lasts 2 turns
  - Mindstorm - an effect -> mark a single Target as 'Soul-Struck'. Every time you Attack the Marked Target, a Soul-Ripping Stilleto will appear above them. When the Mark ends, each Stilleto will explode, dealing Medium Single Target Spirit Damage. Enemies affected by Verity always take Critical Damage from this Keyword
  <a name = "fission"></a>

 ##### Fission
  Core identity : Constant Energy Consumption, Glass Cannon, Radioactive
  - Passive : Deconstruct - whenever you start your turn with 100% of your Energy, loose a % of your Max HP. The HP drain will continue to ramp up with every turn. Gain increased Energy Regen Rate based on Missing Health
  - Assimilate - deal a Small instance of Blast Fission Damage, and immidietly end ALL elemental keywords currently applied to all Targets hit, from all sources. For each keyword cleansed, restore a set ammoung of Energy and increase the Damage of your next Attack
  - Feedback - 
  - Synthesize - a buff -> consume 20% of the Targets Current Energy, gaining a DMG% multiplier per each point of Energy consumed in this way. If in the next Attack you defeat a Target, restore 50% of the consumed Energy. This Keyword can be cast without ending your turn, and can be self-casted.
  - Discharge - a debuff -> apply a single Target with this Keyword. Every time they are Attacked, they gain a Stack of Discharge. At max Stack, proc Assimilate and then release an Additional Explosion, dealing High Blast Fission Damage. This explosion benefist from Assimilate's Damage buff
  <a name = "eclipse"></a>
 
 ##### Eclipse
 Core identity :  Reverse expected Result, Convert damage Dealt/Taken into Eclipse
  - Passvie : Echo - 
  - Dusk
  - Twiglight
  - Syzygy
  - Expunge
