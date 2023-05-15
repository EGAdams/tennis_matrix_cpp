import os

# Get the list of files in the directory
print ( "getting list of files in directory... " )

# Get the list of files in the directory
files = os.listdir( './pin_data' )

# print the number of files
print ( 'Number of files: ' + str(len(files)) )

# Iterate over the list of files
for file in files:
    # Open the file in write mode
    print ( 'Clearing pin data for pin: ' + file )
    with open(file, 'w') as f:
        # Write the character "0" to the file
        f.write( '0' )
