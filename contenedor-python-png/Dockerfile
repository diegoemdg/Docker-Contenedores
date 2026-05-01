FROM python:3.11-slim

WORKDIR /usr/src/app

RUN pip install --no-cache-dir Pillow

COPY . .

CMD python src/image_generator.py

