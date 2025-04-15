package com.example.myapplication.data.remote.model

import kotlinx.serialization.Serializable

@Serializable
data class Company(
    val department: String,
    val name: String,
    val title: String,
    val address: Address
)