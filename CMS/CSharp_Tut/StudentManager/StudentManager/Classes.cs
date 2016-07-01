using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace StudentManageClasses
{
    class Subject
    {
        private string name;
        private float test_mark1;
        private float test_mark2;
        private float exam_mark1;
        private float exam_mark2;
        public float sum_mark;

        public Subject()
        {
            this.name = "";
            this.test_mark1 = 0;
            this.test_mark2 = 0;
            this.exam_mark1 = 0;
            this.exam_mark2 = 0;
            this.sum_mark = 0;
        }

        ~Subject() { }

        public Subject this[int index] 
        {
            get
            {
                return this[index];
            }
        }

        public string Name
        {
            get
            {
                return name;
            }
            set
            {
                this.name = value;
            }
        }

        public float TestMark1
        {
            get
            {
                return test_mark1;
            }
            set
            {
                this.test_mark1 = value;
            }
        }

        public float TestMark2
        {
            get
            {
                return test_mark2;
            }
            set
            {
                this.test_mark2 = value;
            }
        }

        public float ExamMark1
        {
            get
            {
                return exam_mark1;
            }
            set
            {
                this.exam_mark1 = value;
            }
        }

        public float ExamMark2
        {
            get
            {
                return exam_mark2;
            }
            set
            {
                this.exam_mark2 = value;
            }
        }

        public void sumMark()
        {
            this.sum_mark = test_mark1 + test_mark2 + exam_mark1 + exam_mark2;
        }
    }

    class Student
    {
        private int id;
        private string name;
        private int age;
        private Subject[] subjects;

        public Student()
        {
            this.id = 0;
            this.name = "Nam";
            this.age = 20;
            this.subjects = new Subject[3];

            for(int i = 0; i < 3; i++)
            {
                subjects[i] = new Subject();
            }
        }

        ~Student() { }

        public int Id
        {
            get
            {
                return id;
            }
            set
            {
                this.id = value;
            }
        }

        public string Name
        {
            get
            {
                return name;
            }
            set
            {
                this.name = value;
            }
        }

        public int Age
        {
            get
            {
                return age;
            }
            set
            {
                this.age = value;
            }
        }

        public Subject[] Subjects
        {
            get
            {
                return subjects;
            }
        }
    }

    class CourseClass
    {
        private int id;
        private string name;
        private string year;
        private int numberOfStudents;
        List<Student> students;

        public CourseClass()
        {
            this.id = 1;
            this.name = "12A";
            this.numberOfStudents = 0;
            this.students = new List<Student>();
        }

        ~CourseClass() { }

        public int Id
        {
            get
            {
                return id;
            }
            set
            {
                this.id = value;
            }
        }

        public string Name
        {
            get
            {
                return name;
            }
            set
            {
                this.name = value;
            }
        }

        public string Year
        {
            get
            {
                return year;
            }
            set
            {
                this.year = value;
            }
        }

        public int NumberOfStudents
        {
            get
            {
                return numberOfStudents;
            }
            set
            {
                this.numberOfStudents = value;
            }
        }

        public List<Student> Students
        {
            get
            {
                return students;
            }
            set
            {
                this.students = value;
            }
        }
    }
}