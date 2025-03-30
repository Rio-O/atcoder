#python継承#クラス多相ともいう
# クラスAnimalのサブクラスであるDogとCat
class Animal:
    def make_sound(self):
        pass

class Dog(Animal):
    def make_sound(self):
        return "Woof!"

class Cat(Animal):
    def make_sound(self):
        return "Meow!"

# 多相性を活用する関数
def animal_sound(animal):
    return animal.make_sound()

# オブジェクトの動的な多相性を示す例
dog = Dog()
cat = Cat()

sound1 = animal_sound(dog)  # 結果: "Woof!"
sound2 = animal_sound(cat)  # 結果: "Meow!"

print(sound1, sound2)