API Reference
*************

Vec3f
=====

A vector class with 3 floating point components.

.. tabs::

  .. tab:: Python

    .. autoclass:: cxxpythondocs.Vec3f
      :members:

    **Example Usage**

    .. doctest::

       >>> from cxxpythondocs import Vec3f
       >>> vec = Vec3f(1, 2, 3)
       >>> print(vec.x, vec.y, vec.z)
       1.0 2.0 3.0
       >>> vec.DotProduct(Vec3f(-1, -1, 1))
       0.0

  .. tab:: C++

    .. doxygenclass:: cxxpythondocs::Vec3f
       :project: CXXPythonDocs
       :members:

Operations
==========

A collection of math operations.

.. tabs::

  .. tab:: Python

    .. autofunction:: cxxpythondocs.AddIntegers

    **Example Usage**

    .. doctest::

       >>> from cxxpythondocs import AddIntegers
       >>> AddIntegers(1, 2)
       3

  .. tab:: C++

    .. doxygenfunction:: cxxpythondocs::AddIntegers
       :project: CXXPythonDocs
