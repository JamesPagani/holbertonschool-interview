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
