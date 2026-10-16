import math
import matplotlib.pyplot as plt


def forward_kinematics(length1, length2,
                       theta1_deg, theta2_deg):

    # Convert angles from degrees to radians
    theta1 = math.radians(theta1_deg)
    theta2 = math.radians(theta2_deg)

    # Base position
    base = (0.0, 0.0)

    # First joint (elbow) position
    elbow_x = length1 * math.cos(theta1)
    elbow_y = length1 * math.sin(theta1)

    elbow = (elbow_x, elbow_y)

    # End-effector position
    end_x = elbow_x + length2 * math.cos(theta1 + theta2)
    end_y = elbow_y + length2 * math.sin(theta1 + theta2)

    end_effector = (end_x, end_y)

    return base, elbow, end_effector


def main():

    print("TWO-LINK ROBOT ARM KINEMATICS")

    try:
        length1 = float(input("Enter first link length: "))
        length2 = float(input("Enter second link length: "))

        theta1 = float(input("Enter first joint angle: "))
        theta2 = float(input("Enter second joint angle: "))

    except ValueError:
        print("Please enter valid numeric values.")
        return

    if length1 <= 0 or length2 <= 0:
        print("Link lengths must be positive.")
        return

    base, elbow, end = forward_kinematics(
        length1, length2, theta1, theta2
    )

    print("\nROBOT ARM COORDINATES")

    print(f"Base: {base}")
    print(f"Elbow: {elbow}")
    print(f"End Effector: {end}")

    x_values = [base[0], elbow[0], end[0]]
    y_values = [base[1], elbow[1], end[1]]

    plt.figure(figsize=(6, 6))

    plt.plot(
        x_values,
        y_values,
        marker="o",
        linewidth=3
    )

    plt.scatter(
        [end[0]],
        [end[1]],
        label="End Effector"
    )

    plt.axhline(0)
    plt.axvline(0)

    plt.grid(True)
    plt.axis("equal")

    plt.xlabel("X Position")
    plt.ylabel("Y Position")

    plt.title("Two-Link Robot Arm")
    plt.legend()

    plt.show()


if __name__ == "__main__":
    main()
