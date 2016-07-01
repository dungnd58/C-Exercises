using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using StudentManageClasses;

namespace StudentManagerUX
{
    class UIUX
    {
        public UIUX() { }

        ~UIUX() { }

        public List<CourseClass> getDataFromDB()
        {
            List<CourseClass> classes = new List<CourseClass>();

            classes.Add(new CourseClass() { Id = 1, Name = "12A", NumberOfStudents = 0 });
            classes.Add(new CourseClass() { Id = 2, Name = "12B", NumberOfStudents = 0 });

            for (int i = 0; i < 2; i++)
            {
                string fName = "databases/" + classes[i].Name + ".txt";
                using(FileStream file = new FileStream(fName, FileMode.OpenOrCreate, FileAccess.Read, FileShare.Read))
                {
                    using(StreamReader stream = new StreamReader(file))
                    {
                        int line = 0;
                        int studentID = 0;

                        while (!stream.EndOfStream)
                        {
                            if (line == 0)
                            {
                                classes[i].Name = stream.ReadLine();
                            } else if (line == 1)
                            {
                                classes[i].Year = stream.ReadLine();
                            } else if (line == 2)
                            {
                                classes[i].NumberOfStudents = int.Parse(stream.ReadLine());
                            } else
                            {
                                if(studentID < classes[i].NumberOfStudents)
                                {
                                    Student student = new Student();
                                    student.Id = studentID + 1;
                                    student = getStudentInfoFromDB(student, stream);

                                    classes[i].Students.Add(student);

                                    studentID++;
                                }
                                
                            }
                            
                            line++;
                        }

                        file.Close();
                    }

                }

                
            }
            
            return classes;
        }

        public Student getStudentInfoFromDB(Student student, StreamReader stream)
        {
            string[] studentInfo = (stream.ReadLine()).Split(',');

            int i = 0;
            foreach (string info in studentInfo)
            {

                if(i == 0)
                {
                    student.Name = info;
                } else if (i == 1)
                {
                    student.Age = int.Parse(info);
                } if(i >= 2)
                {
                    break;
                }

                i++;
            }
            
            return student;
        }

        public int chooseAClass(List<CourseClass> classes)
        {
            foreach(CourseClass courseClass in classes)
            {
                Console.WriteLine("{0}. {1}", courseClass.Id, courseClass.Name);
            }


            Console.Write("~ Please choose the class: ");
            int class_id = int.Parse(Console.ReadLine());
            Console.Write("\n");

            return class_id;
        }

        public List<Student> enterStudentInfo(List<Student> students, int currNumberOfStudents)
        {
            Console.Write("~ Please enter the number of students: ");
            int numberOfStudents = int.Parse(Console.ReadLine());
            Console.Write("\n");

            int i;
            for(i = currNumberOfStudents; i < currNumberOfStudents + numberOfStudents; i++)
            {
                Console.WriteLine("Student ID: {0}", i+1);

                Console.Write("     Name: ");
                string name = Console.ReadLine();

                Console.Write("     Age: ");
                int age = int.Parse(Console.ReadLine());

                students.Add( new Student(){ Id = i + 1, Name = name, Age = age } );

                Console.Write("\n");
            }

            return students;
        }

        public void enterAStudentMark(List<Student> students)
        {
            Console.Write("~ Please enter the student's ID: ");
            int studentID = int.Parse(Console.ReadLine()) - 1;

            int check = students.FindIndex(student => student.Id == studentID + 1);

            if (check >= 0)
            {
                for (int i = 0; i < 3; i++)
                {
                    Console.Write("{0}. Subject: ", i + 1);
                    students[studentID].Subjects[i].Name = Console.ReadLine();

                    Console.Write("     Test Mark 1: ");
                    students[studentID].Subjects[i].TestMark1 = float.Parse(Console.ReadLine(), CultureInfo.InvariantCulture);

                    Console.Write("     Test Mark 2: ");
                    students[studentID].Subjects[i].TestMark2 = float.Parse(Console.ReadLine(), CultureInfo.InvariantCulture);

                    Console.Write("     Exam Mark 1: ");
                    students[studentID].Subjects[i].ExamMark1 = float.Parse(Console.ReadLine(), CultureInfo.InvariantCulture);

                    Console.Write("     Exam Mark 2: ");
                    students[studentID].Subjects[i].ExamMark2 = float.Parse(Console.ReadLine(), CultureInfo.InvariantCulture);

                    students[studentID].Subjects[i].sumMark();
                }
            }
            else
            {
                Console.WriteLine("~ This student is not in the class.");
            }
        }

        public void printAClassResults(List<Student> students)
        {
            Console.WriteLine("~ The list of students: ");

            foreach (Student student in students)
            {
                Console.WriteLine("Student ID: {0}", student.Id);
                Console.WriteLine("     Name: {0}", student.Name);
                Console.WriteLine("     Age: {0}", student.Age);

                for(int i = 0; i < 3; i++)
                {
                    Console.WriteLine("{0}. Subject: {1}", i + 1, student.Subjects[i].Name);
                    Console.WriteLine("     Test Mark 1: {0}", student.Subjects[i].TestMark1);
                    Console.WriteLine("     Test Mark 2: {0}", student.Subjects[i].TestMark2);
                    Console.WriteLine("     Exam Mark 1: {0}", student.Subjects[i].ExamMark1);
                    Console.WriteLine("     Exam Mark 2: {0}", student.Subjects[i].ExamMark2);
                }

                Console.Write("\n");
            }
        }

        public void printAStudentResult(List<Student> students)
        {
            Console.Write("~ Please enter the student's ID: ");
            int studentID = int.Parse(Console.ReadLine()) - 1;

            Student student = students[studentID];

            Console.WriteLine("Student ID: {0}", student.Id);
            Console.WriteLine("     Name: {0}", student.Name);
            Console.WriteLine("     Age: {0}", student.Age);

            for (int i = 0; i < 3; i++)
            {
                Console.WriteLine("{0}. Subject: {1}", i + 1, student.Subjects[i].Name);
                Console.WriteLine("     Test Mark 1: {0}", student.Subjects[i].TestMark1);
                Console.WriteLine("     Test Mark 2: {0}", student.Subjects[i].TestMark2);
                Console.WriteLine("     Exam Mark 1: {0}", student.Subjects[i].ExamMark1);
                Console.WriteLine("     Exam Mark 2: {0}", student.Subjects[i].ExamMark2);
            }

            Console.Write("\n");
        }
    }
}