# 訪問者クラス
class Visitor:
    def visit_circle(self, circle):
        print("Visiting Circle")

    def visit_rectangle(self, rectangle):
        print("Visiting Rectangle")

# 要素クラス
class Shape:
    def accept(self, visitor):
        pass

class Circle(Shape):
    def accept(self, visitor):
        visitor.visit_circle(self)

class Rectangle(Shape):
    def accept(self, visitor):
        visitor.visit_rectangle(self)

# クライアントコード
s = Shape()
circle = Circle()
rectangle = Rectangle()

visitor = Visitor()

circle.accept(visitor)     # 出力: Visiting Circle
rectangle.accept(visitor)  # 出力: Visiting Rectangle
s.accept(visitor)
