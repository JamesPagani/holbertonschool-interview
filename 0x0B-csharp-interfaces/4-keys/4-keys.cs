using System;

///<summary>Interface for interactive classes.</summary>
interface IInteractive
{
    ///<summary>Interact with something</summary>
    void Interact();
}

///<summary>Interface for breakable classes.</summary>
interface IBreakable
{
    ///<summary>Durability of the instance.</summary>
    int durability {get; set;}

    ///<summary>Break the instance.</summary>
    void Break();
}

///<summary>Interface for collectable classes.</summary>
interface ICollectable
{
    ///<summary>Has this instance been collected?</summary>
    bool isCollected {get; set;}

    ///<summary>Collect this instance.</summary>
    void Collect();
}

///<summary>A random abstract class.</summary>
abstract class Base
{
    ///<summary>Unofficial name of the instance.</summary>
    public string name {get; set;}

    ///<summary>Prints the type of the instance.</summary>
    public override string ToString()
    {
        return $"{name} is a {GetType().Name}";
    }
}

///<summary>A class that inherits from a class and interfaces.</summary>
class TestObject : Base, IInteractive, IBreakable, ICollectable
{
    ///<summary>Durability of the instance.</summary>
    public int durability {get; set;}
    
    ///<summary>Has this instance been collected?</summary>
    public bool isCollected {get; set;}

    ///<summary>Interact with something</summary>
    public void Interact()
    {
        throw new NotImplementedException();
    }

    ///<summary>Break the insstance.</summary>
    public void Break()
    {
        throw new NotImplementedException();
    }

    ///<summary>Collect this instance.</summary>
    public void Collect()
    {
        throw new NotImplementedException();
    }
}

///<summary>A door.</summary>
class Door : Base, IInteractive
{


    ///<summary>Create a new door with a name.</summary>
    public Door(string name)
    {
        this.name = name;
    }

    ///<summary>Try to open the door.</summary>
    public void Interact()
    {
        Console.WriteLine($"You try to open {this.name}. It's locked.");
    }
}

class Decoration : Base, IInteractive, IBreakable
{
    ///<summary>Is this decoration important?</summary>
    public bool isQuestItem;
    ///<summary>Durability of the decoration.</summary>
    public int durability {get; set;}

    ///<summary>Create a new instance of Decoration</summary>
    public Decoration(string Name = "Decoration", int Durability = 1, bool IsQuestItem = false)
    {
        if (Durability <= 0)
        {
            throw new Exception("Durability must be greater than 0");
        }
        this.name = Name;
        this.durability = Durability;
        this.isQuestItem = IsQuestItem;    
    }

    ///<summary>Interact with the decoration.</summary>
    public void Interact()
    {
        if (durability <= 0)
        {
            Console.WriteLine($"The {this.name} has been broken");
        }
        else
        {
            if (isQuestItem)
                Console.WriteLine($"You look at the {this.name}. There's a key inside.");
            else
                Console.WriteLine($"You look at the {this.name}. Not much to see here.");
        }
    }

    ///<summary>Damage the decoration.</summary>
    public void Break()
    {
        durability--;
        if (durability > 0)
            Console.WriteLine($"You hit the {this.name}. It cracks.");
        else if (durability == 0)
            Console.WriteLine($"You smash the {this.name}. What a mess.");
        else
            Console.WriteLine($"The {this.name} is already broken.");
    }
}

class Key : Base, ICollectable
{
    public bool isCollected {get; set;}
    
    public Key(string Name = "Key", bool IsCollected = false)
    {
        this.name = Name;
        this.isCollected = IsCollected;
    }

    public void Collect()
    {
        if (!isCollected)
        {
            isCollected = true;
            Console.WriteLine($"You pick up the {name}.");
        }
        else
        {
            Console.WriteLine($"You have already picked up the {name}.");
        }
    }
}
