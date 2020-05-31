# -*- coding: UTF-8 -*-

import os
from setuptools import setup, Extension

cwd = os.path.dirname(os.path.abspath(__file__))


if __name__ == "__main__":
    lib_dir = os.path.join(cwd, "build")

    extention = Extension(
        "kcp",
        # libraries=["kcpwrapper"],
        ["kcp.c"],
        # language="c",
        # extra_compile_args=['-std=c++17'],
        # include_dirs=[cwd],
        # library_dirs=[lib_dir],
    )

    setup(name="kcp",
          version="1.0.0",
          description="A Simple Kcp Library.",
          author="Hui",
          author_email="yuwenhuisama@outlook.com",
          ext_modules=[extention]
        )
