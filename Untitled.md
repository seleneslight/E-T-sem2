### Power Series
**Radius of convergence:**
_Ratio test:_
$$L = \lim_{n \to \infty} \left| \frac{a_{n+1}}{a_n} \right| \quad R = \frac{1}{L}$$
_Root test:_$$L = \lim_{n \to \infty} \sqrt[n]{|a_n|} \quad R = \frac{1}{L}$$
**Centered at $x_0$:$$\sum_{n=0}^{\infty} a_n (x - x_0)^n$$
- **Converges at:** $|x - x_0| < R$
- **Check endpoints at:** $x = x_0 \pm R$
### Fourier Series
**For period $2\pi$, interval $x \in \langle -\pi, \pi \rangle$:**
$$f(x) = \frac{a_0}{2} + \sum_{n=1}^{\infty} \left[ a_n \cos(nx) + b_n \sin(nx) \right]$$
$$a_0 = \frac{1}{\pi} \int_{-\pi}^{\pi} f(x) dx$$
$$a_n = \frac{1}{\pi} \int_{-\pi}^{\pi} f(x) \cos(nx) dx \quad n \ge 1$$
$$b_n = \frac{1}{\pi} \int_{-\pi}^{\pi} f(x) \sin(nx) dx$$
**For period $2l$, interval $x \in \langle -l, l \rangle$:**
$$f(x) = \frac{a_0}{2} + \sum_{n=1}^{\infty} \left[ a_n \cos \left(\frac{n\pi x}{l}\right) + b_n \sin \left(\frac{n\pi x}{l}\right) \right]$$
$$a_0 = \frac{1}{l} \int_{-l}^{l} f(x) dx$$
$$a_n = \frac{1}{l} \int_{-l}^{l} f(x) \cos \left(\frac{n\pi x}{l}\right) dx \quad n \ge 1$$
$$b_n = \frac{1}{l} \int_{-l}^{l} f(x) \sin \left(\frac{n\pi x}{l}\right) dx$$
**For interval $x \in \langle -\frac{l}{2}, \frac{l}{2} \rangle$:**
$$f(x) = \frac{a_0}{2} + \sum_{n=1}^{\infty} \left[ a_n \cos \left(\frac{2n\pi x}{l}\right) + b_n \sin \left(\frac{2n\pi x}{l}\right) \right]$$
$$a_0 = \frac{2}{l} \int_{-\frac{l}{2}}^{\frac{l}{2}} f(x) dx$$
$$a_n = \frac{2}{l} \int_{-\frac{l}{2}}^{\frac{l}{2}} f(x) \cos \left(\frac{2n\pi x}{l}\right) dx \quad n \ge 1$$
$$b_n = \frac{2}{l} \int_{-\frac{l}{2}}^{\frac{l}{2}} f(x) \sin \left(\frac{2n\pi x}{l}\right) dx$$
### Dirichlet's Conditions
**On interval $\langle a, b \rangle$:**
1. $f$ is piecewise monotonic (finite monotonic)
2. $f$ is continuous on $\langle a, b \rangle$ (finite discontinuities)
3. Internal points:$$f(x_0) = \frac{1}{2} \left( \lim_{x \to x_0^+} f(x) + \lim_{x \to x_0^-} f(x) \right)$$
4. Endpoints: $$f(a) = f(b) = \frac{1}{2} \left( \lim_{x \to a^+} f(x) + \lim_{x \to b^-} f(x) \right)$$
### Fourier Identities & Inequalities
**Bessel's Inequality:**
$$\frac{a_0^2}{2} + \sum_{m=1}^{k} (a_m^2 + b_m^2) \le \frac{1}{\pi} \int_{-\pi}^{\pi} [f(x)]^2 dx$$
**Parseval's Identity:**
$$\frac{a_0^2}{2} + \sum_{n=1}^{\infty} (a_n^2 + b_n^2) = \frac{1}{\pi} \int_{-\pi}^{\pi} [f(x)]^2 dx$$
### Laplace Transform
**For the second-order linear ordinary differential equation:**
$$ay'' + by' + cy = g(t)$$
**The Laplace transform is:**
$$a[s^2 Y(s) - s y(0) - y'(0)] + b[s Y(s) - y(0)] + c Y(s) = G(s)$$