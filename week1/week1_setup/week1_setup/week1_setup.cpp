// =====================================================================
//  CGJ - Lab 2 (GLM) - Training file
//  Each exercise is a function. In main(), uncomment the one you want
//  to run and press F5.
// =====================================================================

#include <iostream>
#include <cstdlib>
#include <ctime>

#define GLM_ENABLE_EXPERIMENTAL          // needed for glm::to_string (must come before the includes)
#include <glm/glm.hpp>
#include <glm/gtx/string_cast.hpp>       // glm::to_string    -> print vectors/matrices
#include <glm/gtc/random.hpp>            // glm::linearRand   -> random vectors
#include <glm/gtc/epsilon.hpp>           // glm::epsilonEqual -> compare floats safely
#include <glm/gtc/matrix_transform.hpp>  // glm::rotate, glm::translate, glm::scale

// ---------------------------------------------------------------------
//  Helpers (shared by all exercises)
// ---------------------------------------------------------------------
const float EPSILON = 1e-3f;

glm::vec3 randomVec3()
{
    return glm::linearRand(glm::vec3(-10.0f), glm::vec3(10.0f));
}

bool areEqual(const glm::vec3& a, const glm::vec3& b)
{
    // Floats have rounding errors: compare each component with a tolerance
    return glm::all(glm::epsilonEqual(a, b, EPSILON));
}

void print(const std::string& name, const glm::vec3& v)
{
    std::cout << name << " = " << glm::to_string(v) << "\n";
}


// =====================================================================
//  EXERCISE 1 (SOLVED - reference)
//  Show that the cross product is distributive over addition:
//      u x (v + w) = u x v + u x w
//  Test with random vectors and show intermediate results.
// =====================================================================
bool isCrossDistributive(const glm::vec3& u, const glm::vec3& v, const glm::vec3& w)
{
    // Left side
    glm::vec3 vPlusW = v + w;
    glm::vec3 left   = glm::cross(u, vPlusW);

    // Right side
    glm::vec3 uCrossV = glm::cross(u, v);
    glm::vec3 uCrossW = glm::cross(u, w);
    glm::vec3 right   = uCrossV + uCrossW;

    print("u            ", u);
    print("v            ", v);
    print("w            ", w);
    print("v + w        ", vPlusW);
    print("u x (v + w)  ", left);
    print("u x v        ", uCrossV);
    print("u x w        ", uCrossW);
    print("u x v + u x w", right);

    return areEqual(left, right);
}

void exercise1()
{
    std::cout << "===== EXERCISE 1: cross product is distributive =====\n";
    for (int i = 1; i <= 5; i++)
    {
        std::cout << "--- Test " << i << " ---\n";
        bool ok = isCrossDistributive(randomVec3(), randomVec3(), randomVec3());
        std::cout << (ok ? "EQUAL -> distributive holds\n\n" : "NOT EQUAL\n\n");
    }
}


// =====================================================================
//  PRACTICE 1 - Anti-commutativity
//  Show that  u x v = -(v x u)
//  Test with 5 random vectors and show intermediate results.
// =====================================================================
bool isCrossAntiCommutative(const glm::vec3& u, const glm::vec3& v)
{
    // TODO 1: compute u x v
    // TODO 2: compute v x u
    // TODO 3: compute -(v x u)
    // TODO 4: print u, v and every intermediate result
    // TODO 5: return whether u x v and -(v x u) are equal (use areEqual)
    return false;
}

void practice1()
{
    std::cout << "===== PRACTICE 1: cross product is anti-commutative =====\n";
    for (int i = 0; i < 5; i++) {
        glm::vec3 u = randomVec3();
        glm::vec3 v = randomVec3();
        glm::vec3 left_side = glm::cross(u, v);
        glm::vec3 right_side = -(glm::cross(v, u));
        bool equal = areEqual(left_side, right_side);
        
        print("u", u);
        print("v", v);
        print("v x u", left_side);
        print("-(u x v)", right_side);
        std::cout << (equal ? "EQUAL -> distributive holds\n\n" : "NOT EQUAL\n\n");

     
    }
}


// =====================================================================
//  PRACTICE 2 - Associativity
//  Check whether  (u x v) x w = u x (v x w)
//  Test with 5 random vectors and show intermediate results.
//  Questions:
//    a) What does it print most of the time? What does that tell you?
//    b) Test again with w = u. Is it equal now?
// =====================================================================
bool isCrossAssociative(const glm::vec3& u, const glm::vec3& v, const glm::vec3& w)
{
    // TODO 1: compute (u x v) x w
    // TODO 2: compute u x (v x w)
    // TODO 3: print every intermediate result
    // TODO 4: return whether they are equal
    return false;
}

void practice2()
{
    std::cout << "===== PRACTICE 2: is the cross product associative? =====\n";
    for (int i = 0; i < 5; i++) {
        glm::vec3 u = randomVec3();
        glm::vec3 v = randomVec3();
        glm::vec3 w = randomVec3();

        glm::vec3 first_left_side = glm::cross(u,v);
        glm::vec3 second_left_side = glm::cross(first_left_side, w);

        glm::vec3 first_right_side = glm::cross(v, w);
        glm::vec3 second_right_side = glm::cross(u, first_right_side);

        bool equal = areEqual(second_left_side, second_right_side);

        print("u", u);
        print("v", v);
        print("w", w);

        print("u x v", first_left_side);
        print("(u x v) x w", second_left_side);

        print("v x w", first_right_side);
        print("u x (v x w)", second_right_side);

        std::cout << (equal ? "EQUAL -> associative holds\n\n" : "NOT EQUAL\n\n");
    }
}


// =====================================================================
//  PRACTICE 3 - Cross product is orthogonal (prep for Lab Exercise 4)
//  For random u and v, compute n = u x v and print:
//      dot(n, u)  and  dot(n, v)
//  Question: what values do you get, and why?
//  Extra: also print glm::normalize(n) and its length (glm::length).
// =====================================================================
void practice3()
{
    std::cout << "===== PRACTICE 3: u x v is orthogonal to u and v =====\n";
    for (int i = 0; i < 5; i++) {
        glm::vec3 u = randomVec3();
        glm::vec3 v = randomVec3();
        glm::vec3 w = randomVec3();


    }
}



// =====================================================================
//  LAB EXERCISES 2-5 (from the lab PDF) - for you to solve
// =====================================================================

// EXERCISE 2: Using GLM, implement the rotations Rx = 45 deg and Ry = 90 deg
// as matrices and apply them to u = [1,1,1], v = [-1,-1,0], w = [1,0,0].
// Hints: glm::rotate(glm::mat4(1.0f), glm::radians(45.0f), axis)
//        to rotate a vec3: glm::vec3(R * glm::vec4(u, 1.0f))
void exercise2()
{
    std::cout << "===== EXERCISE 2: rotation matrices =====\n";
    glm::vec3 u = glm::vec3(1, 1, 1);
    glm::vec3 v = glm::vec3(-1, -1, 0);
    glm::vec3 w = glm::vec3(1, 0, 0);
    float angle1 = 45.0f;
    float angle2 = 90.0f;

    glm::mat4 rx45 = glm::rotate(glm::mat4(1.0f), glm::radians(angle1), glm::vec3(1, 0, 0));
    glm::mat4 ry90 = glm::rotate(glm::mat4(1.0f), glm::radians(angle2), glm::vec3(0, 1, 0));

    glm::vec3 rx45_u = glm::vec3(rx45 * glm::vec4(u, 1.0f));
    glm::vec3 rx45_v = glm::vec3(rx45 * glm::vec4(v, 1.0f));
    glm::vec3 rx45_w = glm::vec3(rx45 * glm::vec4(w, 1.0f));
    glm::vec3 ry90_u = glm::vec3(ry90 * glm::vec4(u, 1.0f));
    glm::vec3 ry90_v = glm::vec3(ry90 * glm::vec4(v, 1.0f));
    glm::vec3 ry90_w = glm::vec3(ry90 * glm::vec4(w, 1.0f));

    print("u", u);
    print("v", v);
    print("w", w);

    print("rx45_u", rx45_u);
    print("rx45_v", rx45_v);
    print("rx45_w", rx45_w);

    print("ry90_u", ry90_u);
    print("ry90_v", ry90_v);
    print("ry90_w", ry90_w);
}


glm::vec3 rotate(glm::mat4 r, glm::vec3 u) {
    return glm::vec3(r * glm::vec4(u, 1.0f));
}


// EXERCISE 3: Show that 3D rotations are NOT commutative (unlike 2D).
// Test with random vectors: is Rx * Ry * p equal to Ry * Rx * p ?
void exercise3()
{
    std::cout << "===== EXERCISE 3: rotation order =====\n";
    float angle = 45.0f;

    glm::mat4 rx45 = glm::rotate(glm::mat4(1.0f), glm::radians(angle), glm::vec3(1, 0, 0));
    glm::mat4 ry45 = glm::rotate(glm::mat4(1.0f), glm::radians(angle), glm::vec3(0, 1, 0));

    for (int i = 0; i < 5; i++) {
        glm::vec3 u = randomVec3();
        glm::vec3 v = randomVec3();
        glm::vec3 w = randomVec3();

        glm::vec3 ru1 = rotate(ry45, rotate(rx45, u));
        glm::vec3 ru2 = rotate(rx45, rotate(ry45, u));
        bool equal1 = areEqual(ru1, ru2);

        glm::vec3 rv1 = rotate(ry45, rotate(rx45, v));
        glm::vec3 rv2 = rotate(rx45, rotate(ry45, v));
        bool equal2 = areEqual(rv1, rv2);

        glm::vec3 rw1 = rotate(ry45, rotate(rx45, w));
        glm::vec3 rw2 = rotate(rx45, rotate(ry45, w));
        bool equal3 = areEqual(rw1, rw2);

        std::cout << "--- Iteration " << i + 1 << " ---\n";

        print("u", u);
        print("Ry(45) * Rx(45) * u", ru1);
        print("Rx(45) * Ry(45) * u", ru2);
        std::cout << (equal1 ? "EQUAL -> rotations holds\n\n" : "NOT EQUAL\n\n");

        print("v", v);
        print("Ry(45) * Rx(45) * v", rv1);
        print("Rx(45) * Ry(45) * v", rv2);
        std::cout << (equal2 ? "EQUAL -> rotation holds\n\n" : "NOT EQUAL\n\n");

        print("w", w);
        print("Ry(45) * Rx(45) * w", rw1);
        print("Rx(45) * Ry(45) * w", rw2);
        std::cout << (equal3 ? "EQUAL -> rotation holds\n\n" : "NOT EQUAL\n\n");

        std::cout << "\n";
    }
}

// EXERCISE 4: Plane with basis a = [1,2,3], b = [4,5,6].
//   - orthogonalVector(a, b): returns a UNIT vector orthogonal to both
//   - areOrthogonal(a, b, c): returns whether c is orthogonal to a and b
//   Test with a, b above and with the 2D cartesian basis.
//   What happens if you swap the vectors in orthogonalVector?

glm::vec3 orthogonalVector(const glm::vec3& a, const glm::vec3& b)
{
    return glm::normalize(glm::cross(a, b));
}


bool areOrthogonal(const glm::vec3& a, const glm::vec3& b, const glm::vec3& c)
{
    float dotA = glm::dot(a, c);
    float dotB = glm::dot(b, c);
    std::cout << "  a . c = " << dotA << "   b . c = " << dotB << "\n";   // intermediate results
    return std::abs(dotA) < EPSILON && std::abs(dotB) < EPSILON;
}

void exercise4()
{
    std::cout << "===== EXERCISE 4: orthogonal vectors =====\n";

    // --- Test 1: the plane from the lab ---
    glm::vec3 a(1, 2, 3);
    glm::vec3 b(4, 5, 6);
    glm::vec3 n = orthogonalVector(a, b);
    glm::vec3 n2 = orthogonalVector(b, a);   // swapped

    print("a", a);
    print("b", b);
    print("a x b (not normalized)", glm::cross(a, b));
    print("orthogonalVector(a, b)", n);
    std::cout << "  length = " << glm::length(n) << "\n";
    print("orthogonalVector(b, a)", n2);

    std::cout << "Is n orthogonal to a and b?\n";
    std::cout << (areOrthogonal(a, b, n) ? "  YES\n" : "  NO\n");
    std::cout << "Is a orthogonal to a and b? (should be NO)\n";
    std::cout << (areOrthogonal(a, b, a) ? "  YES\n" : "  NO\n");

    // --- Test 2: 2D cartesian basis ---
    glm::vec3 x(1, 0, 0);
    glm::vec3 y(0, 1, 0);
    glm::vec3 nxy = orthogonalVector(x, y);
    print("\northogonalVector(x, y)", nxy);
    print("orthogonalVector(y, x)", orthogonalVector(y, x));
    std::cout << (areOrthogonal(x, y, nxy) ? "  YES\n" : "  NO\n");
}

// EXERCISE 5: (see the diagram in the lab PDF)
//   - Encode the center unit square as a matrix
//   - Find the transformations that produce the other squares
//   - Implement both in GLM (glm::translate, glm::scale, glm::rotate)
void exercise5()
{
    std::cout << "===== EXERCISE 5: transforming the unit square =====\n";

    // ---- The center unit square: each column is a corner (homogeneous point, w = 1)
    glm::mat4 square(
        glm::vec4(-0.5f, 0.5f, 0.0f, 1.0f),   // A
        glm::vec4(0.5f, 0.5f, 0.0f, 1.0f),   // B
        glm::vec4(0.5f, -0.5f, 0.0f, 1.0f),   // C
        glm::vec4(-0.5f, -0.5f, 0.0f, 1.0f));  // D

    const glm::vec3 Z(0, 0, 1);               // 2D rotation = rotation around Z
    const glm::mat4 I(1.0f);

    // ---- Square 1: rotate -45 deg, then move to (2, 1)
    glm::mat4 R1 = glm::rotate(I, glm::radians(-45.0f), Z);
    glm::mat4 T1 = glm::translate(I, glm::vec3(2.0f, 1.0f, 0.0f));
    glm::mat4 M1 = T1 * R1;                   // read right-to-left: R1 first, then T1

    // ---- Square 2: scale x2, rotate 180 deg, then move to (-2, -2)
    glm::mat4 S2 = glm::scale(I, glm::vec3(2.0f, 2.0f, 1.0f));   // z = 1, not 0!
    glm::mat4 R2 = glm::rotate(I, glm::radians(180.0f), Z);
    glm::mat4 T2 = glm::translate(I, glm::vec3(-2.0f, -2.0f, 0.0f));
    glm::mat4 M2 = T2 * R2 * S2;              // S2 first, then R2, then T2

    // ---- Apply: one multiplication transforms all 4 corners
    glm::mat4 square1 = M1 * square;
    glm::mat4 square2 = M2 * square;

    const char* names[] = { "A", "B", "C", "D" };
    std::cout << "Original      Square 1 (')      Square 2 (\")\n";
    for (int i = 0; i < 4; i++)
    {
        std::cout << names[i] << " = " << glm::to_string(glm::vec2(square[i]))
            << "   " << names[i] << "' = " << glm::to_string(glm::vec2(square1[i]))
            << "   " << names[i] << "\" = " << glm::to_string(glm::vec2(square2[i])) << "\n";
    }
}


// =====================================================================
//  MAIN - uncomment the exercise you want to run
// =====================================================================
int main()
{
    std::srand(static_cast<unsigned>(std::time(nullptr)));   // different random numbers each run

    //exercise1();
    //practice1();
     //practice2();
    // practice3();
    //exercise2();
     //exercise3();
    // exercise4();
    exercise5();

    return 0;
}
