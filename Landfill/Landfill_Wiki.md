This is the Wiki page to document the details about the Landfill functionality.

# Overview:

The Landfill functionality is supposed to simulate the amount of trash gathered within the city in the given simulation time.

# File Management:

'Landfill.cpp' is the file that contains the various functions that calculate the trash created within the city.

## Functions:

**Landfill**
- This function declares the landfill as a "zone type" but one that is not simulated on the map. It simply stores the maximum capacity of trash.

**acceptTrash**
- This function simply checks to make sure that the supposed amount of trash within the city is able to be stored in the landfill. If the amount of trash to be moved is more than what the landfill is able to handle, it denies the trash being moved and declares that the landfill is full. 

**getCurrTrash**
- This function just grabs the amount of trash that needs to be moved through the city. 

**genTrash**
- This function is the heart of the entire functionality. It parses through the city throughout the different zones and multiplies the population in that respective zone by the multiplier given to that zone type to obtain the amount of trash that the respective zone produces. Residential, Commercial, Industrial, and Hospital have 1, 1.5, 2, 1.75 multipliers respectively. This functionality also creates a variable "totTrashGen" which stores the total amount of trash gathered during that timestep. 

