package appli;

import java.io.*;
import java.util.Scanner;

public class Div
{

 public static void main(String[] a)
    {
	Scanner sc=new Scanner(System.in);
	System.out.println("entrez un entier e1:");
	int e1=sc.nextInt();
	System.out.println("entrez un entier e2:");
	int e2=sc.nextInt();
	
	System.out.println("entrez un flottant f1:");
	float f1=sc.nextFloat();
	System.out.println("entrez un entier e2:");
	float f2=sc.nextFloat();
	
	System.out.println("e1/e2 = "+ e1/e2);
	System.out.println("f1/f2 = "+ f1/f2);
	
    }
}
    
