
//The construction of abstract class is justified because the abstract class gives a common method shared by all with 
//object specific declaration for each of the sub classes.

abstract class Shapes{
    float pi = 3.14f;
    abstract void surface_area();
    abstract void Volume();
}

class cylinder extends Shapes{
    
    float r;
    float h;
    
    cylinder(float rr,float hh)
    {
        r = rr;
        h = hh;
    }

    void surface_area()
    {
        float sa = 2*pi*r*h;
        System.out.println("surface area of cylinder = " + sa);
    }

    void Volume()
    {
        float vol = pi*r*r*h;
        System.out.println("volume of Cylinder = " + vol);
    }
};

class Sphere extends Shapes{
    
    float r;
    Sphere(float rr)
    {
        r = rr;
    }

    void surface_area()
    {
        float sa = 4*pi*r*r;
        System.out.println("surface area of Sphere = " + sa);
    }

    void Volume()
    {
        float vol = (4.0f*pi*r*r*r)/3.0f;
        System.out.println("volume of Sphere = " + vol);
    }
};

class Cube extends Shapes{

    float a;
    Cube(float aa)
    {
        a = aa;
    }

    void surface_area()
    {
        float sa = 6*a*a;
        System.out.println("Surface area of cube = " + sa);
    }

    void Volume()
    {
        float vol = a*a*a;
        System.out.println("vol of Cube = " + vol);
    }
};

public class abc{

    public static void main(String args[])
    {
        cylinder cyl = new cylinder(5.0f,5.0f);
        Sphere spy = new Sphere(3.0f);
        Cube cub = new Cube(4.0f);

        cyl.surface_area();
        cyl.Volume();

        spy.surface_area();
        spy.Volume();

        cub.surface_area();
        cub.Volume();
    }
} 