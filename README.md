
# Simple Game for Simple People


1. A scene type
- A scene contains objects, characters, paths to new scenes, descriptions etc.
- Scenes can be serialized and deserialized (see point 2)
- Scenes are serialized when left and deserialized when entered
2. Serialization
- Create serializable and deserializable objects
- Allows for someone to resume the game after quitting
- Allows for us to use the de/serializing to go into and out of scenes.
    - Ex: Check if file exists, if not, new scene, start from scratch.
- We will use an abstract serializer for each class
    - Ex: `serialize(std::cout, Gun());`
- Possible implementation:
    * Have an abstract Serializable like the following:
      b. Integrates with the standard library.
        * disadvantages
          a. a serializer needs to be implemented for every type (except types like std::string, int, float, etc. since the standard library implements those for you)
3. Argument parser
- provides an easy way to extract meaning from text
- Split on words to allow for text that has extra whitespace in it (e.g. "  hi    there").
- Uses approximate string matching to detect typos and notify the user (e.g. "I don't know that command. Did you mean ...").