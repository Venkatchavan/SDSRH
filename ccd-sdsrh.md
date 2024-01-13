Clean Code Development Cheat Sheet
1. Meaningful Names:
Choose clear and descriptive names for variables, functions, and classes.
Avoid single-letter variable names unless their scope is limited (e.g., loop indices).
2. Separation of Concerns:
Break down large functions into smaller, focused ones, each addressing a specific concern.
Each function/method should do one thing and do it well.
3. Comments:
Use comments sparingly; aim for self-explanatory code.
Comments should provide insights into why something is done, not just describe what is done.
4. Formatting:
Consistent indentation and formatting for improved readability.
Follow a consistent coding style.
5. Functionality:
Avoid the use of magic numbers; use constants or enums instead.
Replace hard-coded file names and modes with constants.
6. Error Handling:
Implement proper error handling, including meaningful error messages.
Avoid using exit(0) for program termination; prefer returning from functions or using exceptions.
7. Avoid Global Variables:
Minimize the use of global variables; prefer passing parameters or using local variables.
8. Class Design:
Encapsulate related functions and data into classes.
Follow SOLID principles: Single Responsibility, Open/Closed, Liskov Substitution, Interface Segregation, Dependency Inversion.
9. Consistent Naming Conventions:
Follow consistent naming conventions for variables, classes, and functions.
Choose descriptive and consistent names for constants.
10. Remove Redundancy:
Remove unnecessary code or comments.
Keep the codebase clean and focused on the essentials.
