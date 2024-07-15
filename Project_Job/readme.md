# Software system for job allocation

This software is designed to efficiently allocate jobs to candidates based on their academic qualifications and requirements. It considers various
factors such as vacancies, work experience, expected salary etc.

# Problem Statement

To create a mediating platform through which Job seekers can explore the open positions which match their profiles and Talent acquisition managers 
can search for deserving applicants who could qualify for their job requirements. 

In today's competitive environment getting jobs and searching for candidates assume greater importance. Earlier job advertisements were limited to 
newspapers and physical ads. Now various online portals, employment exchanges and company websites exist. Hence its crucial to create a concise and
effective platform through which job seekers and talent acquisition teams (i.e employers, etc) can get jobs and get required employers.

# Requirements

C compilers such as gcc
Software for code Development

# Input

Seeker : Seeker job constraints
Employer : Employer job constraints

# Output

Seeker : List of eligible jobs with percentage match
Employer : List of eligible candidates and list of candidates to whome job has been allocated

# How to run the code 

Open compiler
Compiling :  gcc final.c -o app
Running   :  ./app

# Working

Seeker side : 

Based on the academic qualifications a score is calculated. Constraints such as Expected Salary, Work Experience etc. are obtained from the seeker. Priority order of constraints is input from the seeker and list of available jobs are displayed. The seeker can choose from the list of available jobs.

Employer side :

Constraints and requirements of the company are input from the employer. The applicants' profiles which matches with the requirements of the company is displayed. The employer can also look at the applicants to which job has already been allocated

# Conclusion

This software is a basic software to allocate jobs to seekers and display list of eligible candidates to employers. This software has some limitations which can be rectified in the future.

# Authors

R.Rohan (3122 22 5001 109)
R.Rohan (3122 22 5001 108)
Rupnarayan.B (3122 22 5001 114)