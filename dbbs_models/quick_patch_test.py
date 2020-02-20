from patch import p
import numpy as np

soma = p.Section()
ascending_axon = p.Section()
parallel_fiber = p.Section()

ascending_axon.nseg = 18
ascending_axon.L = 126
ascending_axon.diam = 0.3
ascending_axon.connect(soma)

position = [0., 0., 0.]

y = 16.62232

ascending_axon.add_3d([
    position + [0., y, 0.],
    position + [0., y + ascending_axon.L, 0.]])

parallel_fiber.nseg = 285
parallel_fiber.L = 2000
parallel_fiber.diam = 0.3

parallel_fiber.add_3d([
    position + [0., 100+y,  - round(parallel_fiber.L/2)],
    position + [0., 100+y, + round(parallel_fiber.L/2)]])

parallel_fiber.connect(ascending_axon)
