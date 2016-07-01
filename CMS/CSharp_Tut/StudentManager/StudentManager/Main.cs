using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using StudentManageClasses;
using StudentManagerUX;

namespace StudentManager
{
    class MainProgram
    {
        static void Main(string[] args)
        {
            UIUX ui_ux = new UIUX();

            List<CourseClass> classes = ui_ux.getDataFromDB();

            int choice = 0;

            while (choice != 5)
            {
                Console.WriteLine("--- Options ---");
                Console.WriteLine("1. Enter the student's infomation.");
                Console.WriteLine("2. Enter the student's marks.");
                Console.WriteLine("3. Show a student's result.");
                Console.WriteLine("4. Show the student's result of a class.");
                Console.WriteLine("5. Exit.");
                Console.Write("\n~ Please enter your choice: ");
                choice = int.Parse(Console.ReadLine());
                Console.Write("\n");

                switch (choice)
                {
                    case 1:
                        {
                            int class_id = ui_ux.chooseAClass(classes) - 1;
                            classes[class_id].Students = ui_ux.enterStudentInfo(classes[class_id].Students,classes[class_id].NumberOfStudents);

                            classes[class_id].NumberOfStudents = classes[class_id].Students.Count;

                            Console.WriteLine(classes[class_id].NumberOfStudents);

                            Console.WriteLine("~ Completed.");
                            break;
                        }
                    case 2:
                        {
                            int class_id = ui_ux.chooseAClass(classes) - 1;
                            ui_ux.enterAStudentMark(classes[class_id].Students);
                            break;
                        }
                    case 3:
                        {
                            int class_id = ui_ux.chooseAClass(classes) - 1;
                            ui_ux.printAStudentResult(classes[class_id].Students);
                            break;
                        }
                    case 4:
                        {
                            int class_id = ui_ux.chooseAClass(classes) - 1;
                            ui_ux.printAClassResults(classes[class_id].Students);
                            break;
                        }
                    case 5:
                        {
                            Console.Write("Please enter any key to EXIT.");
                            break;
                        }
                    default:
                        Console.Write("Invalid choice. Please choose again!");
                        break;
                }

                Console.Write("\n");
            }

            Console.ReadKey();
        }
    }
}
