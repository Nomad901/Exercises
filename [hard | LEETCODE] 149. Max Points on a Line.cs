using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Security.Authentication.ExtendedProtection;
using System.Text;
using System.Threading.Tasks;
using System.Xml;
using System.Xml.XPath;

namespace ConsoleApp3
{
    internal class Program
    {
        static public bool arePointsCollinear((Int32, Int32) pPoint1, (Int32, Int32) pPoint2, (Int32, Int32) pPoint3)
        {
            return (pPoint2.Item2 - pPoint1.Item2) * (pPoint3.Item1 - pPoint1.Item1) ==
                   (pPoint3.Item2 - pPoint1.Item2) * (pPoint2.Item1 - pPoint1.Item1);
        }

        static public Int32 maxPoints(Int32[][] points)
        {
            List<(Int32 x, Int32 y)> positions = new List<(Int32 x, Int32 y)>();

            foreach (var point in points)
            {
                positions.Add((point[0], point[1]));
            }

            if (positions.Count() == 1 || positions.Count() == 2)
                return positions.Count();

            Int32 counter = 0;
            bool isFirstTime = true;
            for (Int32 i = 0; i < positions.Count() - 2; ++i)
            {
                if (arePointsCollinear(positions[i], positions[i + 1], positions[i + 2]))
                {
                    if (isFirstTime)
                    {
                        counter += 3;
                        isFirstTime = false;
                    }
                    else
                        counter++;
                }
            }

            return counter;
        }

        static void Main(string[] args)
        {
            int[][] points = new int[][] 
            {
                new int[] {0, 0},
                new int[] {1,-1},
                new int[] {1, 1}
            };
            Console.WriteLine(maxPoints(points));
        }
    }
}
