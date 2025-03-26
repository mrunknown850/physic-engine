#include <iostream>
#include <vector>
#include <string>

#include "PhysicsEngine.hpp"
#include "configs.hpp"

enum Commands
{
    CREATE, // Create body
    APPLY,  // Apply force
    DUMP,   // Dumping all body info
    STEP,   // Steping n frame
    EXIT,   // Exit out of sim
};

std::vector<std::string> tokenize_std_input()
{
    std::cout << ">> ";
    std::string command, token;
    std::vector<std::string> tokens;
    const std::string delim = " ";
    size_t pos = 0;
    getline(std::cin, command);
    while ((pos = command.find(delim)) != std::string::npos)
    {
        token = command.substr(0, pos);
        tokens.push_back(token);
        command.erase(0, pos + delim.length());
    }
    tokens.push_back(command);
    return tokens;
}

int main()
{
    std::cout << "Running physic engine at " << FRAME_PER_SECOND << " FPS\n";
    PhysicsEngine physics;

    while (true)
    {
        std::vector<std::string> tokens = tokenize_std_input();
        if (tokens[0] == "CREATE")
        {
            Point3 position(std::stoi(tokens[1]), std::stoi(tokens[2]), std::stoi(tokens[3]));
            float mass = std::stof(tokens[4]);

            int id = physics.CreateObject(Body(position, mass));
            std::cout << "Created Body " << id
                      << " at " << tokens[1] << " " << tokens[2] << " " << tokens[3]
                      << " with mass of " << tokens[4] << std::endl;
        }
        else if (tokens[0] == "APPLY")
        {
            int body_id = std::stoi(tokens[1]);
            Vec3 offset(std::stoi(tokens[2]), std::stoi(tokens[3]), std::stoi(tokens[4]));
            Vec3 direction(std::stoi(tokens[5]), std::stoi(tokens[6]), std::stoi(tokens[7]));
            float duration = std::stoi(tokens[8]);
            Force force(offset, direction, duration);
            physics.applyForce(body_id, force);
            std::cout << "Applied a force to body_id" << tokens[1]
                      << " at " << tokens[2] << " " << tokens[3] << " " << tokens[4]
                      << " relative to object center with the equivilant vector of "
                      << tokens[5] << " " << tokens[6] << " " << tokens[7]
                      << " for " << tokens[8] << " seconds.\n";
        }
        else if (tokens[0] == "DUMP")
        {

            std::cout << "Dumping informations\n";
            for (int t = 0; t < physics.ObjectCount(); t++)
            {
                Body *body = physics.GetObject(t);
                std::cout << "RIGIDBODY INFO #" << t << std::endl;
                std::cout << "- Position: " << body->position.x << " " << body->position.y << " " << body->position.z << std::endl;
                std::cout << "- Mass: " << body->mass << std::endl;
            }
        }
        else if (tokens[0] == "STEP")
        {
            int count = std::stoi(tokens[1]);
            std::cout << "Moved " << count << " frames\n";
            while (count--)
            {
                physics.update();
            }
        }
        else if (tokens[0] == "EXIT")
        {
            std::cout << "Exited\n";
            return 0;
        }
        else
        {
            std::cout << "Invalid Command!\n";
        }
    }
}
