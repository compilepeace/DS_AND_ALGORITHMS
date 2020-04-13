# Instance attributes are those attributes which are not defined in the class but are individually
# alloted to the OBJECTS instead. Meaning that they are not part of the class (blueprint) but are 
# alloted separately after an instance (object) has been created.

# object.__dict__  : gives a dictionary of all attributes of the object


# Simplest class declared
class Binary:
	# Class attributes and methods common to all objects are present here
	pass


# We can asign unique attributes to objects called instance attributes.
# (i.e. attributes that are not specified by the class/object's structure)
infected = Binary()
infected.name = "ps"

# Unique attributes added for 'clean' object 
# (i.e. name and id, that are not specified by the class/object's structure)
clean = Binary()
clean.name = "ls"
clean.id = 1998

print(f"{type(infected)} : {infected.name}")
print(f"{type(clean)} : {clean.name}, {clean.id}")

print("")
print(f"All attributes of {infected.name} (via __dict__ attribute) : {infected.__dict__}")
print(f"All attributes of {clean.name} (via __dict__ attribute) : {clean.__dict__}")
