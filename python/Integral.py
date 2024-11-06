from manim import *


class Integral(Scene):
    def construct(self):
        text1 = Text(r"The Integral of ", color=YELLOW).to_edge(LEFT, buff=3)
        text2 = MathTex(r"\sqrt[3]{tanx}", color=YELLOW).next_to(text1, RIGHT, buff=0.7).scale(1.5)
        self.play(FadeIn(text1, text2))
        self.wait()
        self.play(FadeOut(text1, text2))
        self.wait()

        integral1 = MathTex(r"\int\sqrt[3]{tanx}\, dx")
        self.play(Write(integral1))
        self.wait()
        self.play(integral1.animate.to_edge(UL, buff=0.5))
        self.wait()

        text3 = Text(r"Substituting ", color=YELLOW).to_edge(UP, buff=0.5).to_edge(LEFT, buff=3).scale(0.7)
        text4 = MathTex(r"\sqrt[3]{tanx} = t", color=YELLOW).next_to(text3, RIGHT).to_edge(UP, buff=0.5)
        text5 = Text(r", we get", color=YELLOW).scale(0.7)
        self.play(FadeIn(text3, text4, text5.next_to(text4, RIGHT, buff=0.1).to_edge(UP, buff=0.6)),
                  integral1.animate.to_edge(UP, buff=1.5))
        self.wait(2)

        t_sub1 = MathTex(r"\sqrt[3]{tanx} = t").to_edge(UP, buff=1.5)
        self.play(Write(t_sub1))
        self.wait()
        self.play(FadeOut(text3, text4, text5), integral1.animate.to_edge(UL, buff=0.5),
                  t_sub1.animate.to_edge(UP, buff=0.5))

        t_sub2 = MathTex(r"tanx = t^3").next_to(t_sub1, DOWN)
        self.play(Write(t_sub2))
        self.wait(2)

        text6 = Text(r"Differentiating both sides with respect to x, we get", color=YELLOW).next_to(t_sub2, DOWN).\
            scale(0.5)
        self.play(FadeIn(text6))
        self.wait(2)

        t_sub3 = MathTex(r"\frac{d}{dx}tanx = \frac{d}{dx}t^3").next_to(text6, DOWN)
        self.play(Write(t_sub3))
        self.wait(2)

        transform1 = MathTex(r"sec^2x = 3t^2 \frac{dt}{dx}").next_to(text6, DOWN)
        self.play(ReplacementTransform(t_sub3, transform1))
        self.wait(3)

        t_sub4 = MathTex(r"sec^2x\, dx = 3t^2\, dt").next_to(transform1, DOWN)
        self.play(Write(t_sub4))
        self.wait(2)

        transform2 = MathTex(r"(1 + tan^2x)\, dx = 3t^2\, dt").next_to(transform1, DOWN)
        self.play(ReplacementTransform(t_sub4, transform2))
        self.wait(2)

        t_sub5 = MathTex(r"(1 + (t^3)^2)\, dx = 3t^2\, dt").next_to(transform2, DOWN)
        self.play(Write(t_sub5))
        self.wait(2)

        transform3 = MathTex(r"(1 + t^6)\, dx = 3t^2\, dt").next_to(transform2, DOWN)
        self.play(ReplacementTransform(t_sub5, transform3))
        self.wait(2)

        t_sub6 = MathTex(r"dx = \frac{3t^2}{1+t^6}dt").next_to(transform3, DOWN)
        self.play(Write(t_sub6))
        self.wait(2)

        t_sub1_rev = MathTex(r"t = \sqrt[3]{tanx}").to_edge(UR, buff=0.5).scale(0.5)
        self.play(FadeOut(t_sub2, text6, transform1, transform2, transform3), ReplacementTransform(t_sub1, t_sub1_rev),
                  t_sub6.animate.next_to(t_sub1_rev, DOWN).scale(0.5))
        self.wait()

        integral2 = MathTex(r"\int t \frac{3t^2}{1+t^6}dt")
        self.play(integral1.animate.next_to(integral2, UP))
        self.play(Write(integral2))
        self.wait(5)
        self.play(FadeOut(t_sub6, integral1), integral2.animate.to_edge(UL, buff=0.5))

        text7 = MathTex(r"t^2 = u", color=YELLOW).next_to(text3, RIGHT).to_edge(UP, buff=0.5)
        self.play(FadeIn(text3, text7, text5.next_to(text7, RIGHT, buff=0.1).to_edge(UP, buff=0.6)),
                  integral2.animate.to_edge(UP, buff=1.5))
        self.wait(2)

        u_sub1 = MathTex(r"t^2 = u").to_edge(UP, buff=1.5)
        self.play(Write(u_sub1))
        self.wait(2)

        self.play(FadeOut(text3, text5, text7), u_sub1.animate.to_edge(UP, buff=0.5),
                  integral2.animate.to_edge(UL, buff=0.5))
        self.wait()

        text8 = Text(r"Differentiating both sides with respect to t, we get", color=YELLOW).next_to(u_sub1, DOWN)\
            .scale(0.5)
        self.play(FadeIn(text8))
        self.wait(2)

        u_sub2 = MathTex(r"\frac{d}{dt} t^2 &= \frac{d}{dt} u").next_to(text8, DOWN)
        self.play(Write(u_sub2))
        self.wait(3)

        transform4 = MathTex(r"2t = \frac{du}{dt}").next_to(text8, DOWN)
        self.play(ReplacementTransform(u_sub2, transform4))
        self.wait(3)

        u_sub3 = MathTex(r"2t\, dt = du").next_to(transform4, DOWN)
        self.play(Write(u_sub3))
        self.wait(3)

        transform5 = MathTex(r"t\, dt = \frac{du}{2}").next_to(transform4, DOWN)
        self.play(ReplacementTransform(u_sub3, transform5))
        self.wait(3)

        u_sub1_rev = MathTex(r"u = t^2").next_to(t_sub1_rev, DOWN).scale(0.5)
        self.play(FadeOut(u_sub2, text8, transform4),
                  ReplacementTransform(u_sub1, u_sub1_rev), transform5.animate.next_to(u_sub1_rev, DOWN).scale(0.5))
        self.wait()

        self.play(integral2.animate.move_to(ORIGIN).to_edge(UP, buff=0.5))
        self.wait(2)

        integral3 = MathTex(r"3 \int \frac{t^2}{1+(t^2)^3} tdt").next_to(integral2, DOWN)
        self.play(Write(integral3))
        self.wait(3)

        integral4 = MathTex(r"3 \int \frac{u}{1+u^3} \frac{du}{2}").next_to(integral3, DOWN)
        self.play(Write(integral4))
        self.wait(3)
        self.play(FadeOut(transform5))

        integral5 = MathTex(r"\frac{3}{2} \int \frac{u}{1+u^3} du").next_to(integral4, DOWN)
        self.play(Write(integral5))
        self.wait(3)

        text9 = Text("We know that, ", color=YELLOW).next_to(integral5, DOWN).to_edge(LEFT, buff=3).scale(0.5)
        text10 = MathTex(r"(a+b)^3 = (a-b)(a^2 - ab + b^2)", color=YELLOW).next_to(text9, RIGHT, buff=-0.9).scale(0.7)
        self.play(FadeIn(text9, text10))
        self.wait(3)

        integral6 = MathTex(r"\frac{3}{2} \int \frac{u}{(1+u)(u^2-u+1)} du").next_to(integral5, DOWN, buff=1)
        self.play(Write(integral6))
        self.wait(3)
        self.play(FadeOut(integral2, integral3, integral4, integral5, text9, text10),
                  integral6.animate.to_edge(UP, buff=0.5))

        text11 = Text("Using Partial Fractions, we get", color=YELLOW).next_to(integral6, DOWN).scale(0.7)
        self.play(FadeIn(text11))
        self.wait(2)

        partial1 = MathTex(r"\frac{u}{(1+u)(u^2-u+1)} = \frac{A}{u+1} + \frac{Bu+C}{u^2-u+1}").next_to(text11, DOWN)
        self.play(Write(partial1))
        self.wait(5)

        partial2 = MathTex(r"\frac{u}{(1+u)(u^2-u+1)} = \frac{A(u^2-u+1)+(Bu+C)(u+1)}{(u+1)(u^2-u+1)}").next_to(
            partial1, DOWN)
        self.play(Write(partial2))
        self.wait(5)

        partial3 = MathTex(r"u = A(u^2-u+1)+(Bu+C)(u+1)").next_to(partial2, DOWN)
        self.play(Write(partial3))
        self.wait(5)

        partial4 = MathTex(r"u = A(u^2-u+1)+Bu(u+1)+C(u+1)").next_to(partial3, DOWN)
        self.play(Write(partial4))
        self.wait(5)

        partial5 = MathTex(r"u = Au^2-Au+A + Bu^2+Bu + Cu+C").next_to(partial4, DOWN)
        self.play(Write(partial5))
        self.wait(5)

        transform6 = MathTex(r"\frac{3}{2} \int \frac{A}{u+1} + \frac{Bu+C}{u^2-u+1}").to_edge(UP, buff=0.5)
        self.play(ReplacementTransform(integral6, transform6),
                  FadeOut(partial1, partial2, partial3, partial4), partial5.animate.next_to(text11, DOWN))
        self.wait(2)

        partial6 = MathTex(r"u = (A+B)u^2 + (B+C-A)u + (A+C)").next_to(partial5, DOWN)
        self.play(Write(partial6))
        self.wait(5)

        text12 = Text("From this we get 3 equations, that is", color=YELLOW).next_to(partial6, DOWN).scale(0.5)
        self.play(FadeIn(text12))
        self.wait(3)

        eq1 = MathTex(r"A+B &= 0 \\ B+C-A &= 1 \\ A+C &= 0").next_to(text12, DOWN).to_edge(LEFT, buff=0.5)
        self.play(Write(eq1))
        self.wait(5)

        text13 = Text("By solving these set of equations\nWe get the values of A, B and C", color=YELLOW).next_to(
            text12, DOWN).to_edge(RIGHT, buff=-1).scale(0.5)
        self.play(FadeIn(text13))
        self.wait(5)

        eq2 = MathTex(r"A = -\frac{1}{3}\, B = \frac{1}{3} \, C = \frac{1}{3}").next_to(text13, DOWN)
        self.play(Write(eq2))
        self.wait(3)

        text14 = Text("Substituting the values of A, B and C into the integral, we get",
                      color=YELLOW).next_to(eq2, DOWN).to_edge(RIGHT, buff=-0.5).scale(0.5)
        self.play(FadeIn(text14))
        self.wait(3)

        transform7 = MathTex(r"\frac{3}{2}\int\frac{-\frac{1}{3}}{u+1}+\frac{\frac{1}{3}u+\frac{1}{3}}{u^2-u+1} du").\
            to_edge(UP,buff=0.5)
        self.play(FadeOut(text11, partial5, partial6, text12, eq1, text13, eq2, text14),
                  ReplacementTransform(transform6, transform7))
        self.wait(3)

        integral7 = MathTex(r"\frac{3}{2}.\frac{1}{3} \int \frac{-1}{u+1} + \frac{u+1}{u^2-u+1} du").\
            next_to(transform7, DOWN)
        self.play(Write(integral7))
        self.wait(3)

        integral8 = MathTex(r"\frac{1}{2} \int \frac{-1}{u+1} + \frac{u+1}{u^2-u+1} du").next_to(integral7, DOWN)
        self.play(Write(integral8))
        self.wait(3)

        integral9 = MathTex(r"\frac{1}{2} \int \frac{-1}{u+1}du + \frac{1}{2} \int \frac{u+1}{u^2-u+1}du").\
            next_to(integral8, DOWN)
        self.play(Write(integral9))
        self.wait(3)

        integral10 = MathTex(r"-\frac{1}{2} \ln|u+1| + \frac{1}{2} \int \frac{u+1}{u^2-u+1}du").next_to(integral9, DOWN)
        self.play(Write(integral10))
        self.wait(5)
        self.play(FadeOut(transform7, integral7, integral8, integral9), integral10.animate.to_edge(UP, buff=0.5))

        text15 = Text("We know, Numerator = A(d/dx Denominator) + B, we get", color=YELLOW).\
            next_to(integral10, DOWN).scale(0.5)
        self.play(FadeIn(text15))
        self.wait(3)

        sub1 = MathTex(r"u+1 = A\frac{d}{du}(u^2-u+1) + B").next_to(text15, DOWN)
        self.play(Write(sub1))
        self.wait(5)

        transform8 = MathTex(r"u+1 = A(2u-1) + B").next_to(text15, DOWN)
        self.play(ReplacementTransform(sub1, transform8))
        self.wait(3)

        sub2 = MathTex(r"u+1 = 2Au - A + B").next_to(transform8, DOWN)
        self.play(Write(sub2))
        self.wait(3)

        text16 = Text("From the above equation, we get", color=YELLOW).next_to(sub2, DOWN).scale(0.5)
        self.play(FadeIn(text16))
        self.wait(3)

        sub3_1 = MathTex(r"u = 2Au").next_to(text16, DOWN).to_edge(LEFT, buff=4)
        sub3_2 = MathTex(r"1 = B-A").next_to(text16, DOWN).to_edge(RIGHT, buff=4)
        self.play(Write(sub3_1))
        self.play(Write(sub3_2))
        self.wait(3)

        text17 = Text("Solving these equations, we get", color=YELLOW).next_to(text16, DOWN, buff=1).scale(0.5)
        self.play(FadeIn(text17))
        self.wait(3)

        sub4_1 = MathTex(r"A = \frac{1}{2}").next_to(text17, DOWN).to_edge(LEFT, buff=4)
        sub4_2 = MathTex(r"B = \frac{3}{2}").next_to(text17, DOWN).to_edge(RIGHT, buff=4)
        self.play(Write(sub4_1))
        self.play(Write(sub4_2))
        self.wait(3)

        text18 = Text("Substituting the value of numerator into the integral, we get", color=YELLOW).\
            next_to(text17, DOWN, buff=1.5).scale(0.5)
        self.play(FadeIn(text18))
        self.wait(3)
        self.play(FadeOut(text15, transform8, sub2, text16, sub3_1, sub3_2, text17, sub4_1, sub4_2, text18))
        self.wait()

        integral11 = MathTex(r"-\frac{1}{2}\ln|u+1|+\frac{1}{2}\int\frac{\frac{1}{2}(2u-1)+\frac{3}{2}}{u^2-u+1}du").\
            next_to(integral10, DOWN)
        self.play(Write(integral11))
        self.wait(7)

        integral12 = MathTex(r"-\frac{1}{2} \ln|u+1| + \frac{1}{4} \int \frac{2u-1+3}{u^2-u+1}du").\
            next_to(integral11, DOWN)
        self.play(Write(integral12))
        self.wait(5)

        integral13 = MathTex(
            r"-\frac{1}{2}\ln|u+1|+\frac{1}{4}\int\frac{2u-1}{u^2-u+1}du+\frac{3}{4}\int\frac{du}{u^2-u+1}").\
            next_to(integral12, DOWN)
        self.play(Write(integral13))
        self.wait(5)
        self.play(FadeOut(integral10, integral11, integral12), integral13.animate.to_edge(UP, buff=0.5).scale(0.7))

        text19 = Text(r"Substituting ", color=YELLOW).next_to(integral13, DOWN).to_edge(LEFT, buff=3).scale(0.5)
        text20 = MathTex(r"u^2 - u + 1 = v", color=YELLOW).next_to(text19, RIGHT, buff=-1.1).\
            next_to(integral13, DOWN).scale(0.7)
        text21 = Text(r", we get", color=YELLOW).next_to(text20, RIGHT, buff=-0.4).scale(0.5)
        self.play(FadeIn(text19, text20, text21))
        self.wait(5)

        v_sub1 = MathTex(r"u^2 - u + 1 = v").next_to(integral13, DOWN, buff=1)
        self.play(Write(v_sub1))
        self.wait(2)

        text22 = Text(r"Differentiating both sides with respect to u, we get", color=YELLOW).next_to(v_sub1, DOWN).\
            scale(0.5)
        self.play(FadeIn(text22))
        self.wait(3)

        v_sub2 = MathTex(r"\frac{d}{du}(u^2-u+1) = \frac{d}{du}v").next_to(text22, DOWN)
        self.play(Write(v_sub2))
        self.wait(3)

        transform9 = MathTex(r"2u-1 = \frac{dv}{du}").next_to(text22, DOWN)
        self.play(ReplacementTransform(v_sub2, transform9))
        self.wait(3)

        v_sub3 = MathTex(r"(2u-1) \,du = dv").next_to(transform9, DOWN)
        self.play(Write(v_sub3))
        self.wait(3)

        v_sub1_rev = MathTex(r"v = u^2 - u + 1").next_to(u_sub1_rev, DOWN).scale(0.5)
        self.play(FadeOut(text19, text20, text21, text22, transform9), ReplacementTransform(v_sub1, v_sub1_rev),
                  v_sub3.animate.next_to(v_sub1_rev, DOWN).scale(0.5))
        self.wait()

        integral14 = MathTex(r"-\frac{1}{2}\ln|u+1|+\frac{1}{4}\int\frac{dv}{v}+\frac{3}{4}\int\frac{du}{u^2-u+1}").\
            next_to(integral13, DOWN).scale(0.7)
        self.play(Write(integral14))
        self.wait(5)
        self.play(FadeOut(v_sub3))

        integral15 = MathTex(r"-\frac{1}{2}\ln|u+1|+\frac{1}{4}\ln|v|+\frac{3}{4}\int\frac{du}{u^2-u+1}").\
            next_to(integral14, DOWN).scale(0.7)
        self.play(Write(integral15))
        self.wait(5)

        text23 = Text("using completing square method, we get", color=YELLOW).next_to(integral15, DOWN).scale(0.5)
        self.play(FadeIn(text23))
        self.wait(3)

        integral16 = MathTex(r"-\frac{1}{2}\ln|u+1|+\frac{1}{4}\ln|v|+\frac{3}{4}\int\frac{du}{[u^2-\frac{1}{2}.2u+\
            (\frac{1}{2})^2]-(\frac{1}{2})^+ 1").next_to(text23, DOWN).scale(0.7)
        self.play(Write(integral16))
        self.wait(10)

        integral17 = MathTex(
            r"-\frac{1}{2}\ln|u+1|+\frac{1}{4}\ln|v|+\frac{3}{4}\int\frac{du}{(u^2-\frac{1}{2})^2-\frac{1}{4}+1}").\
            next_to(integral16, DOWN).scale(0.7)
        self.play(Write(integral17))
        self.wait(7)
        self.play(FadeOut(integral13, integral14, integral15, text23, integral16),
                  integral17.animate.to_edge(UP, buff=0.5))

        integral18 = MathTex(r"-\frac{1}{2}\ln|u+1|+\frac{1}{4}\ln|v|+\frac{3}{4}\int\frac{du}{(u^2-\frac{1}{2})^2+\
            (\frac{\sqrt3}{2})^2}").next_to(integral17, DOWN).scale(0.7)
        self.play(Write(integral18))
        self.wait(7)

        text24 = Text("We know, ", color=YELLOW).next_to(integral18, DOWN, buff=0.5).to_edge(LEFT, buff=3).scale(0.5)
        text25 = MathTex(r"\int \frac{dx}{x^2 + a^2} = \frac{1}{a} \tan^{-1} \frac{x}{a} + C", color=YELLOW).\
            next_to(integral18, DOWN).next_to(text24, RIGHT, buff=-0.9).scale(0.7)
        self.play(FadeIn(text24, text25))
        self.wait(5)

        text26 = MathTex(r"x = (u - \frac{1}{2})", color=YELLOW).next_to(text25, DOWN).to_edge(LEFT, buff=4).scale(0.7)
        text27 = MathTex(r"a = \frac{\sqrt3}{2}", color=YELLOW).next_to(text25, DOWN).to_edge(RIGHT, buff=4).scale(0.7)
        self.play(FadeIn(text26, text27))
        self.wait(7)

        integral19 = MathTex(r"-\frac{1}{2}\ln|u+1|+\frac{1}{4}\ln|v|+\frac{3}{4}.\frac{2}{\sqrt3}\tan^{-1}\frac{2(u-\
            \frac{1}{2})}{\sqrt3}+C").next_to(integral18, DOWN, buff=2.5).scale(0.7)
        self.play(Write(integral19))
        self.wait(15)

        integral20 = MathTex(r"-\frac{1}{2}\ln|u+1|+\frac{1}{4}\ln|v|+\frac{\sqrt3}{2}\tan^{-1}\frac{2u-1}{\sqrt3}+C").\
            next_to(integral19, DOWN).scale(0.7)
        self.play(Write(integral20))
        self.wait(5)
        self.play(FadeOut(integral17, integral18, text24, text25, text26, text27, integral19),
                  integral20.animate.to_edge(UP, buff=0.5))

        text28 = Text("Substituting the value of v into the integral, we get", color=YELLOW).\
            next_to(integral20, DOWN).scale(0.5)
        self.play(FadeIn(text28))
        self.wait(3)

        integral21 = MathTex(
            r"-\frac{1}{2}\ln|u+1|+\frac{1}{4}\ln|u^2-u+1|+\frac{\sqrt3}{2}\tan^{-1}\frac{2u-1}{\sqrt3}+C")\
            .next_to(text28, DOWN).scale(0.7)
        self.play(Write(integral21))
        self.wait(7)
        self.play(FadeOut(v_sub1_rev))

        integral22 = MathTex(
            r"\frac{1}{4}\ln|u^2-u+1|-\frac{1}{2}\ln|u+1|+\frac{\sqrt3}{2}\tan^{-1}\frac{2u-1}{\sqrt3}+C").\
            next_to(integral21, DOWN).scale(0.7)
        self.play(Write(integral22))
        self.wait(5)

        text29 = Text("Substituting the value of u into the integral, we get", color=YELLOW).\
            next_to(integral22, DOWN).scale(0.5)
        self.play(FadeIn(text29))
        self.wait(3)

        integral23 = MathTex(r"\frac{1}{4}\ln|(t^2)^2-(t^2)+1|-\frac{1}{2}\ln|t^2+1|+\frac{\sqrt3}{2}\tan^{-1}\
            \frac{2t^2-1}{\sqrt3}+C").next_to(text29, DOWN).scale(0.7)
        self.play(Write(integral23))
        self.wait(10)
        self.play(FadeOut(u_sub1_rev))

        integral24 = MathTex(r"\frac{1}{4}\ln|t^4-t^2+1|-\frac{1}{2}\ln|t^2+1|+\frac{\sqrt3}{2}\tan^{-1}\frac{2t^2-1}\
            {\sqrt3}+C").next_to(integral23, DOWN).scale(0.7)
        self.play(Write(integral24))
        self.wait(5)
        self.play(FadeOut(integral20, text28, integral21, integral22, text29, integral23),
                  integral24.animate.to_edge(UP, buff=0.5))

        text30 = Text("Substituting the value of t into the integral, we get", color=YELLOW).\
            next_to(integral24, DOWN).scale(0.5)
        self.play(FadeIn(text30))
        self.wait(3)

        integral25 = MathTex(r"\frac{1}{4}\ln|(\sqrt[3]{tanx})^4-(\sqrt[3]{tanx})^2+1|-\frac{1}{2}\ln|(\sqrt[3]{tanx})\
            ^2+1|+\frac{\sqrt3}{2}\tan^{-1}\frac{2(\sqrt[3]{tanx})^2-1}{\sqrt3}+C").next_to(text30, DOWN).scale(0.7)
        self.play(Write(integral25))
        self.wait(10)
        self.play(FadeOut(t_sub1_rev))

        integral26 = MathTex(r"\frac{1}{4}\ln|\tan^{\frac{4}{3}}x-\tan^{\frac{2}{3}}x+1|-\frac{1}{2}\ln|\tan^{\frac{2}\
            {3}}x+1|+\frac{\sqrt3}{2}\tan^{-1}\frac{2\tan^{\frac{2}{3}}x-1}{\sqrt3}+C").next_to(integral25, DOWN).\
            scale(0.7)
        self.play(Write(integral26))
        self.wait(10)

        integral27 = MathTex(r"\frac{1}{4}\ln|\tan^{\frac{4}{3}}x-\tan^{\frac{2}{3}}x+1|-\frac{1}{4}\ln|(\tan^{\frac{2}\
            {3}}x+1)^2|+\frac{\sqrt3}{2}\tan^{-1}\frac{2\tan^{\frac{2}{3}}x-1}{\sqrt3}+C").next_to(integral26, DOWN).\
            scale(0.7)
        self.play(Write(integral27))
        self.wait(7)

        integral28 = MathTex(r"\frac{1}{4}\ln|\frac{\tan^{\frac{4}{3}}x-\tan^{\frac{2}{3}}x+1}{(\tan^{\frac{2}{3}}x+1)\
            ^2}|+\frac{\sqrt3}{2}\tan^{-1}\frac{2\tan^{\frac{2}{3}}x-1}{\sqrt3}+C").next_to(integral27, DOWN).scale(0.7)
        self.play(Write(integral28))
        self.wait(7)
        self.play(FadeOut(integral24, text30, integral25, integral26, integral27))

        integral = MathTex(r"\int\sqrt[3]{tanx}\,dx=\frac{1}{4}\ln|\frac{\tan^{\frac{4}{3}}x-\tan^{\frac{2}{3}}x+1}{(\
            \tan^{\frac{2}{3}}x+1)^2}|+\frac{\sqrt3}{2}\tan^{-1}\frac{2\tan^{\frac{2}{3}}x-1}{\sqrt3}+C").scale(0.7)
        self.play(ReplacementTransform(integral28, integral))
        self.add(integral, SurroundingRectangle(integral, color=PINK))
        self.wait(19)
