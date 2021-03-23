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
