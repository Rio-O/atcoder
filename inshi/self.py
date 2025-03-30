#クラス継承
class pokemon():
    def mnoise(self):
        pass

class pika(pokemon):
    def mnoise(self):
        print("pikachu-")

class ev(pokemon):
    def mnoise(self):
        print("vv")

p = pika()
e = ev()

e.mnoise()
p.mnoise()


#visitor
#ビジタークラスに各処理を記述(引数に適用先を含める)
class Visitor():
    def pikavisit(self, pika):
        print( pika.mnoise() + "chu-" )
    def vvisit(self, ev):
        print( ev.mnoise() + "vv" )

class Pokemon():
    def accept(self, visitor):
        pass

class Pika(Pokemon):
    def accept(self, visitor):
        return visitor.pikavisit(self)
    def mnoise(self):
        return "pikachu-"

class Ev(Pokemon):
    def accept(self, visitor):
        return visitor.vvisit(self)
    def mnoise(self):
        return "vv"

p = Pika()
e = Ev()

v = Visitor()

p.accept(v)
e.accept(v)


#型多相性
def add(a,b):
    return a+b

print(add(1,2), add("yes", "no"))

#クラス多相性elmBST.ml参照すべし
class cal():
    def cal(self):
        pass

class add(cal):
    def cal(self, a, b):
        return a + b

class mult(cal):
    def cal(self, a, b):
        return a * b

def apply(cal, a, b):
    return cal.cal(a, b)

a = add()
b = mult()

print(apply(a, 1, 2), apply(b, 1, 2))


